#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
using namespace std;

template<class Item>
class LinearList{
	private:

	public:
		int MaxSize;
        Item *element;
        int len;
		//Item *element;
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize);

		
		LinearList(const LinearList &b);
		/*{
			cout<<"\nIn copy Constructor\n";
			MaxSize = b.MaxSize;

			len = b.len;
			element = new float;
			//*element = *b.element;
			for(int i=0;i<MaxSize;i++)
			{
				element[i] = b.element[i];
			}
		}*/

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i); //return i'th element of list
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty();

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length();

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize();

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k);

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x);

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x);

		void display();

};

template <class Item> LinearList <Item> :: LinearList(){
	MaxSize=100;
}

template <class Item> LinearList <Item>	:: LinearList(const LinearList &b)
		{
			MaxSize = b.MaxSize;

			len = b.len;
			element = new Item;
			//*element = *b.element;
			for(int i=0;i<MaxSize;i++)
			{
				element[i] = b.element[i];
			}
		}

template <class Item> LinearList <Item> ::LinearList(const int& MaxListSize)
{
	MaxSize = MaxListSize;
	len = 1;
	element = new Item [MaxListSize];
	for(int i=0 ; i<MaxListSize ; i++)
		element[i] = 0;
}

template <class Item> void LinearList <Item> ::display()
{
	for(int i=1 ; i<len ; i++)
	{
		cout<<"element"<<(i)<<"="<<element[i];
		cout<<endl;
	}
}

template <class Item>
LinearList<Item>::~LinearList()
{
	//delete(element);
}

template <class Item> bool LinearList <Item> ::isEmpty()
{
	if(element[1]!=0)
		return false;
	else 
		return true;
}

template <class Item> int LinearList <Item> ::length()
{
	return len-1;
}

template <class Item> int LinearList <Item> ::maxSize()
{
	return MaxSize;
}

template <class Item> Item LinearList <Item> ::returnListElement(const int k)
{
	if(k<MaxSize && k<len)
		return element[k];
	else
		return 0;
}

template <class Item> bool LinearList <Item> ::find(const int k, Item& x)
{
	if(k<=len)
	{
		x = element[k-1];
		return true;
	}
	else
		return false;
}

template <class Item> int LinearList <Item> ::search(Item &k)
{
	int i;
	//cout<<"len = "<<len<<"entered = "<<k<<endl;
	for(i = 0; i<len; i++)
	{	if(element[i] == k)

				return i+1;
	}
			return 0;
}

template <class Item> void LinearList <Item> ::deleteElement(const int  k, Item& x)
{
	int e = k-1;
	int i;
	if(k<=len && k>0)
	{	
		x = element[e];
		//cout<<"x= ";
		for(i = k ; i<len ; i++)
			element[i] = element[i+1];
		element[len] = 0;
		len--;
	}
	else
		cout<<"given position illegal"<<endl;
}

template <class Item> Item& LinearList <Item> ::operator[](const int& i)
{
	int j = i-1;
	return element[j];
}

template <class Item> void LinearList <Item> :: insert(const int x,Item& k)
{
	
	
	int pos = x;
	if(len<=MaxSize && pos<=len)
	{
		if(pos == len)
		{	
			element[pos] = k;
			len++;
		}
		else
		{
		
			for(int i = len ; i>pos ; i--)
			{
				element[i] = element[i-1];
			}
			
			element[pos] = k;
			len++;
		}	

	}
	else
		cout<<"entered value illegal";

}

#endif