#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "seqlinearlist.hpp"
#include "limits.h"

 using namespace std;
 	
 	template<typename T>
 	class MinPriorityQueue{
 		// Private attributes and functions for class
 		// If you need any more functions / attributes
 		// define them yourself along with proper reasoning
 		// why they were introduced.
 		// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
 		// YOU NEED TO USE THEM ALL.


 		// Primary container used in MinPriorityQueue
 		int heap_size;

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos);

		// return the parent of an element
 		inline int parent(const size_t& pos);

 		inline int parent_val(const size_t& pos);

 		// return the left child of an element
 		inline int left_child(const size_t& pos);

 		// return the right child of an element
 		inline int right_child(const size_t& pos);	

 	public:
  		LinearList<T> heap;
 		// default constructor
 		MinPriorityQueue();

 		// construct a heap from the elements of a seqLinearList
		MinPriorityQueue(const LinearList<T>& v);

 		// insert a value to the heap
 		void insert(T a);

 		// get the minimum element from the heap
 		inline T minimum();

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min();

 		// return the heap size
 		inline int heap_size1();	

 		// build a heap from elements of a seqLinearList container 
 		void build_heap(const LinearList<T>& v);

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);	

 		void display();	
 	};

template <class T> int MinPriorityQueue <T>::left_child(const size_t& pos){

 	if(2*pos + 1 <= heap_size)
 		return heap.element[2*pos + 1];
 	else
 		return INT_MAX;
 }

template <class T> int MinPriorityQueue <T>::right_child(const size_t& pos){

 	if(2*pos + 2 <= heap_size)
 		return heap.element[2*pos + 2];
 	else
 		return INT_MAX;
 }

template <class T> int MinPriorityQueue <T>::parent_val(const size_t& pos){
	int pos_;
 		if(pos%2 == 0 && pos<=heap_size)
 			pos_ =  (pos)/2;
 		else if(pos%2 != 0 && pos<=heap_size)
 			pos_ =  (pos-1)/2;

 		return heap.element[pos_];
 }


template <class T> int MinPriorityQueue <T>::parent(const size_t& pos){
	
 		if(pos%2 == 0 && pos<=heap_size)
 			return (pos)/2;
 		else if(pos%2 != 0 && pos<=heap_size)
 			return (pos-1)/2;
 }

template <class T> void MinPriorityQueue <T>::heapify(const size_t& pos)
 	{

 	int j,i;
 	T temp;
 	i = pos;
    temp = heap.element[i];
    j = 2 * i;
    while (j <= heap_size)
    {
        if (j < heap_size && heap.element[j+1] < heap.element[j])
            j = j + 1;
        if (temp < heap.element[j])
            break;
        else if (temp >= heap.element[j])
        {
            heap.element[j/2] = heap.element[j];
            j = 2 * j;
        }
    }
    heap.element[j/2] = temp;
    return;
 	}


template <class T> MinPriorityQueue <T>::MinPriorityQueue()
 	{
 		heap_size = 0;
	}

template <class T> MinPriorityQueue <T>::MinPriorityQueue(const LinearList<T>& v)
	{
		heap = v ;
		heap_size = heap.length();
    	int i;
    	for(i = heap_size/2; i >= 1; i--)
    	{
        	heapify(i);
    	}
	}

template <class T> void MinPriorityQueue <T>::insert(T a)
	{
		heap_size ++;
		heap.insert(heap_size,a);
		heap_decrease_key(heap_size);	
	}

template <class T> void MinPriorityQueue <T>::heap_decrease_key(const size_t& pos)
	{
		int i = pos;
		T temp;

		while(i > 1 && i != INT_MAX)
		{
		int parent_i = parent(i);
			if(parent_i != INT_MAX && parent_i >= 1)
				if(heap.element[parent_i] > heap.element[i])
				{			
				
				temp = heap.element[i];
				heap.element[i] = heap.element[parent_i];
				heap.element[parent_i] = temp;
				}
		i = parent(i);
		
		}	
		cout<<endl;
		//heap.display();
	}

template <class T> T MinPriorityQueue <T>::minimum()
	{
		if(heap_size != 0)
		{	
			int root = 2;
			return heap[root];
		}
	}

template <class T> T MinPriorityQueue <T>::extract_min()
	{
		T min = heap.element[1];
		T x;
		heap.element[1] = heap.element[heap_size];
		heap.deleteElement(heap_size,x);
		heap_size--;
		heapify(1);
		return min;
		//heap.display();
	}

template <class T> int MinPriorityQueue <T>::heap_size1()
	{
		return heap_size;
	}

template <class T> void MinPriorityQueue <T>::build_heap(const LinearList<T>& v)
	{
		heap = v ;
		heap_size = heap.length();
    	int i;
    	for(i = heap_size/2; i >= 1; i--)
    	{
        	heapify(i);
    	}
	}

template <class T> bool MinPriorityQueue <T>::empty()
	{
		if(heap_size)
			return false;
		else
			return true;
	}

template <class T> void MinPriorityQueue <T>::display()
	{
		heap.display();
	}

#endif 