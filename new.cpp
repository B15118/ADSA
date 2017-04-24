P[n].inserted = true;
    P[CPU_priority].delay = 0;
    CPU_priority =  n;
    ch++;
    if(n+1<N)
    {
        if(P[n+1].delay < P[n].burst_time)
        {
            n++;
            counter = counter + P[n].delay;
        }
    }
    
    while(1)
    {   
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
        
            if(counter >= P[i].time)
            {
                if(n>P[i].priority_value  && P[i].inserted == false)
                    n = i;
            }
            else
                break;
        }

        if(ch<N)
        {
            if(q.empty())
            {
                
                cout<<P[n].id<<" \t Running \t"<<counter;
                q.insert(P[n].priority_value);
                P[n].inserted = true;
                CPU_priority =  n;
                ch++;
                if(n+1<N){

                    if(P[n+1].delay < P[n].burst_time){
                        n++;
                        counter = counter+P[n].delay;
                    }
                }
                
                continue;    
            }   

            if(P[CPU_priority].burst_time > P[n].delay && n!=CPU_priority && P[n].burst_time!=0)
            {
                if(P[n].priority_value < P[CPU_priority].priority_value){

      
                    cout<<P[CPU_priority].id<<" \t Pre-empted \t"<<counter<<endl;
                    P[CPU_priority].burst_time = P[CPU_priority].burst_time - P[n].delay;
                }
                else
                {
                    counter = counter + P[CPU_priority].burst_time;
                    cout<<P[CPU_priority].id<<" \t Completed \t"<<counter<<endl;
                    P[CPU_priority].burst_time = 0;
                    q.extract_min();
                    
                }

                cout<<P[n].id<<" \t Running \t"<<counter;
                q.insert(P[n].priority_value);
                CPU_priority =  n;
                //P[CPU_priority].delay = 0;
                P[n].inserted = true;
                ch++;   
            }
            else
            {


                counter = counter + P[CPU_priority].burst_time;
                cout<<P[CPU_priority].id<<" \t Completed \t"<<counter<<endl;
                //P[n].delay = P[n].delay - P[CPU_priority].burst_time;
                counter = counter+P[CPU_priority].burst_time-P[CPU_priority].delay;
                P[CPU_priority].delay=0;
                P[CPU_priority].burst_time = 0;
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
        else
        {
            

            counter = counter + P[CPU_priority].burst_time;
            cout<<P[CPU_priority].id<<" \t Completed \t"<<counter<<endl;
            
            P[CPU_priority].burst_time = 0;
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
            else
            {
                break;
            }
        }       
    }
