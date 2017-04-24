#include "seqlinearlist.hpp"
#include "min_priority_queue.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

class process
{
	public : 
	int id;
	int burst_time;
	int delay;
	int priority_value;
	int counter;
	int time;
	bool inserted;
	bool completed;
};


int main()
{
	
	int CPU_priority=10,N,total_burst_time=0,n=0,i,j,k,counter=0,ch=0,loop=0;
	
	cout<<"Enter the number of interrupt requests\n\nN :  ";
	cin>>N;

	process P[N];

	for (int i = 0; i < N; i++)
	{
		cout<<"\n\nEnter Details\n";
		cout<<"\n\tID["<<i+1<<"] : ";
		cin>>P[i].id;
		cout<<"\n\tBurst Time["<<i+1<<"] : ";
		cin>>P[i].burst_time;
		cout<<"\n\tDelay["<<i+1<<"] : ";
		cin>>P[i].delay;		
		cout<<"\n\tPriority Value["<<i+1<<"] : ";
		cin>>P[i].priority_value;
		P[i].inserted = false;
		P[i].completed = false;
	}

	P[0].time=0;
	for (int i = 1; i < N; i++)
	{
		P[i].time = P[i-1].time + P[i].delay;
	}

	cout<<"\n\n\n";
	cout<<"---------------------------------------------------------------------------------"<<endl;
	cout<<"Sl.No.    I/O Device ID    Burst Time(in ms)    Delay (in ms)    Priority Value\n";
	cout<<"---------------------------------------------------------------------------------\n"<<endl;
	for (int i = 0; i < N; i++)
	{
		cout<<"  "<<i+1<<"\t   "<<P[i].id<<"\t\t    "<<P[i].burst_time<<"\t\t\t   "<<P[i].delay<<"\t\t    "<<P[i].priority_value<<"\n";
		cout<<"---------------------------------------------------------------------------------"<<endl;
	}
	cout<<"\n\n\n";

	MinPriorityQueue<int>q;

	cout<<"ID \t STATUS"<<endl;
	cout<<"-------------------------"<<endl;
	LinearList <int> heap2(N);
	heap2.insert(1,P[0].priority_value);
	q.build_heap(heap2);
	q.extract_min();

	while(1)
	{
		loop=0;	k=0;

		for(i=0;i<N;i++)
        {
            if(counter >= P[i].time && P[i].inserted == false)
            {
                n = i;
                break;
            }
        }	

        for(i=0;i<N;i++)
        {
            if(counter >= P[i].time && P[n].priority_value > P[i].priority_value  && P[i].inserted == false)
                    n = i;
            else
                break;
        }

        if(n == CPU_priority)
        {
        	P[CPU_priority].burst_time = P[CPU_priority].burst_time -1;
        	if(P[CPU_priority].burst_time == 0)
        	{
        		q.extract_min();
        		cout<<P[CPU_priority].id<<" \t Completed2 \t"<<counter+1<<endl;
        		P[CPU_priority].completed = true;
        		 if(!q.empty())
                {
                    for(j=0;j<N;j++)
                    {
                        if(P[j].priority_value == q.minimum())
                        break;
                    }

                    CPU_priority = j;
                    n=j;
                }   
        	}

        }
        else
        {
        	
        	if(q.empty())
        	{
        		 cout<<P[n].id<<" \t Running \t"<<counter;
        		q.insert(P[n].priority_value);
                P[n].inserted = true;
                CPU_priority =  n;
	        	

        		continue;
        	}
        	
        	if(P[CPU_priority].burst_time != 0)
        	{
        		if(P[n].priority_value < P[CPU_priority].priority_value){

                    cout<<P[CPU_priority].id<<" \t Pre-empted \t"<<counter<<endl;

	                cout<<P[n].id<<" \t Running \t"<<counter;
	                q.insert(P[n].priority_value);
	                CPU_priority =  n;
	                P[n].inserted = true;
                }
                else
                {
                	loop=1;
                	 counter = counter+P[CPU_priority].burst_time;
                    cout<<P[CPU_priority].id<<" \t Completed4 \t"<<counter<<endl;

                    P[CPU_priority].completed = true;
                    q.extract_min();
                    cout<<P[n].id<<" \t Running \t"<<counter;
	                q.insert(P[n].priority_value);
	                CPU_priority =  n;
	                P[n].inserted = true;
                   
                }

              
                continue;

        	}
        	else
        	{
                cout<<P[CPU_priority].id<<" \t Completed1 \t"<<counter<<endl;
                P[CPU_priority].completed = true;
                q.extract_min();

                if(!q.empty())
                {
                    for(j=0;j<N;j++)
                    {
                        if(P[j].priority_value == q.minimum())
                        break;
                    }

                    	CPU_priority = j;
                }   
            }

        }

        for(i=0;i<N;i++)
        {
            if(P[i].completed == true)
            {
                k++;
            }
        }
        if(k==N)
        {
        	break;
        }

        counter = counter + 1;
        if(loop==1)
        {
        	counter = counter-1;
        }

       

	}

	return 0; 

}

