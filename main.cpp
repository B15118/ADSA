#include "seqlinearlist.hpp"
#include "min_priority_queue.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int max_size,size,x,choice;
	int min,v,heap_size;
	bool empty;

	cout<<"\nBuild Heap:::::::::::::::::::::\n";
	cout<<"Enter max size of the Heap ";
	cin>>max_size;
	cout<<"Enter size of the Heap ";
	cin>>size;
	LinearList <int> heap2 = LinearList <int> (max_size);
	for(int i = 1 ; i <= size ; i++)
	{
		cout<<"\nEnter element "<<(i)<<" ";
		cin>>x;
		heap2.insert(i,x);
	}

	MinPriorityQueue <int> min_heap;
	min_heap.build_heap(heap2);
	while(1)
	{
	cout<<"\n1.Insert\n2.Minimum\n3.Extract minimum\n4.IsEmpty\n5.Heap Size\n6.Display\n7.Exit\n";
	cin>>choice;
	switch(choice)
		{
		case 1:
				{
					if(size <= max_size)
					{
						cout<<"\nEnter value to be inseted in heap ";
						cin>>v;
						min_heap.insert(v);
						size++;
					}
					else
						cout<<"\nHeap full\n";	
					break;
				}
		case 2:
				{
					int min = min_heap.minimum();
					cout<<min<<endl;
					break;
				}
		case 3:
				{
					if(size > 0)
					{	int min = min_heap.extract_min();
						cout<<min<<endl;
						size--;
					}
					else
						cout<<"\nEmpty heap\n";
					break;
				}
		case 4:
				{
					empty = min_heap.empty();
					if(empty)
						cout<<"empty";
					else
						cout<<"not empty";
					cout<<endl;
				}
		case 5:
				{
					heap_size = min_heap.heap_size1();
					cout<<"\nHeap Size : "<<heap_size;
					break;
				}
		case 6:{
					min_heap.display();
					break;
				}
		case 7:	exit(0);
		
		default:
				cout<<"\nEnter correct option\n";
		}
	}
/*

	cout<<"\nEnter max size";
	cin>>max_size;
	cout<<"\nEnter heap size";
	cin>>size;
	LinearList <int> heap2 = LinearList <int> (max_size);


	for(int i = 1 ; i <= size ; i++)
	{
		cout<<"\nEnter element "<<(i)<<" ";
		cin>>x;
		heap2.insert(i,x);
	}

	cout<<endl;
	MinPriorityQueue <int> min_heap;
	
	min_heap.build_heap(heap2);

	min_heap.display();
	min = min_heap.extract_min();
	min_heap.display();
	min = min_heap.extract_min();
	min_heap.display();
	
	cout<<"\nminimum = "<<min;	*/	
	return 0;
}