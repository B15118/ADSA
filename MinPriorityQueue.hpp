// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
//#include "seqLinearList.hpp"

 namespace cs202{
 	
 	template<typename T>
 	class MinPriorityQueue{
 		// Private attributes and functions for class
 		// If you need any more functions / attributes
 		// define them yourself along with proper reasoning
 		// why they were introduced.
 		// DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
 		// YOU NEED TO USE THEM ALL.


 		// Primary container used in MinPriorityQueue
 		seqLinearList<T> heap;
 		int heap_size;

 		// heapifies the heap at position pos 
 		void heapify(const size_t& pos);

 		// return the parent of an element
 		inline int parent(const size_t& pos);

 		// return the left child of an element
 		inline int left_child(const size_t& pos);

 		// return the right child of an element
 		inline int right_child(const size_t& pos);

 	public:
 		// default constructor
 		MinPriorityQueue();

 		// construct a heap from the elements of a seqLinearList
 		MinPriorityQueue(const seqLinearList<T>& v);

 		// insert a value to the heap
 		void insert(const T& a);

 		// get the minimum element from the heap
 		inline T minimum();

 		// return the minimum element from the heap and remove it
 		// as well
 		T extract_min();

 		// return the heap size
 		inline int heap_size();

 		// build a heap from elements of a seqLinearList container 
 		void build_heap(const seqLinearList<T>& v);

 		// check if MinPriorityQueue is empty
 		inline bool empty();

 		// heap_decrease_key function
 		void heap_decrease_key(const size_t& pos);
 	};
 	
#endif 