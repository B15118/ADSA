#include <iostream>
#include <string.h>
#include <limits.h>

//namespace cs202 {
    template<typename T>
    class LinearList{
      private:
        
        unsigned int size;
        unsigned int capacity;
      public:
        // Default Constructor
        // Creates a zero sized LinearList
        T* element;
        LinearList();

        // Constructor with size as input
        LinearList(const int& isize);                   

        // Constuctor with size and default value as input
        LinearList(const int& isize, const T& ival);    

        // Default Destructor
        ~LinearList();                                  

        // Accessing an element of the LinearList using operator
        inline T& operator[](const int& i);         

        // Return the element in the list at position k
        inline T& at(const int& k);         

        // Appending an element to the LinearList
        // The asymptotic time complexity of this function
        // should be O(1)
        void push_back(const T& item);              

        // Returns true if LinearList is empty
        bool empty();                               

        // Returns the size of the LinearList
        unsigned int getSize();                                 

        // Returns the capacity of the LinearList
        unsigned int getCapacity();                                 

        // Fills all the elements with a default value
        void fill(const T& item);                   

        // Resizes the LinearList
        void resize(const int& n); 

        // Find the index of first occurence of an item in the list
        // Return size of list if item not found
        // 0-based indexing
        int find(const T& item);

        // Remove all occurences of an item in the list
        void erase(const T& item);

        // Remove the item in the list at position pos
        void erase_pos(const int& pos);

        // Insert item at position k
        void insert(const T& item, const int& k);

   
  };


  

    

    template<typename T> LinearList<T> :: LinearList()
    {
        element=new T[1];
        size=0;
        capacity=1;

    }



     template<typename T> LinearList<T> :: LinearList(const int& isize)
    {
            
            int i;
            capacity = isize;
            element=new T[isize];
            
            for(i=0;i<isize;i++)
                element[i]=INT_MAX;
            
            size=0;
    }


    template<typename T>void  LinearList<T> :: resize(const int & n)
    {
       
        T* element1 = new T[n];
       for(int i=0;i<size;i++)
       {

            element1[i]=element[i];
       }
        
        delete[] element;

        element=element1;

        capacity = n;



    } 


    template<typename T> LinearList<T> :: LinearList(const int& isize, const T& ival)
    {
            
            int i;
            capacity = isize;
            element=new T[isize];
            
            for(i=0;i<isize;i++)
                element[i]=ival;
            
            size=0;
    }


     template<typename T> LinearList<T> ::  ~LinearList()
    {                                                                           //DESTRUCTOR
            
            size=0;
            delete []element;
    }



     template<typename T> inline T&  LinearList<T> :: operator[](const int& i)        //PRINTING elementS USING OPERATOR OVERLOADING
    {
        
        return element[i];
    }



     template<typename T>bool  LinearList<T> :: empty()
    {
        if (size==0) 
            return true;
        
        else 
            return false;
    }



     template<typename T>unsigned int  LinearList<T> :: getSize()
    {

        return size;
    }



     template<typename T>unsigned int LinearList<T> ::  getCapacity()                        //FUNCTION TO RETURN THE capacity OF LINEAR LIST
    {
        return capacity;
    }



     template<typename T> T&  LinearList<T> :: at(const int& k)
    {

        return *(element + k);
    }


    template<typename T> void  LinearList<T> :: push_back(const T& k)
    {


        if(size < capacity){

            element[size] = k;
        }
        else{
            
            resize(2*capacity);
           
            element[size] = k;
        }

        size++;
    }



     template<typename T> int LinearList<T> :: find(const T& item)           //FUNCTION TO FIND THE element
    {    

        int i;
        for(i=0;i<size;i++)
        {
            if(element[i]== item)
            {
                return i;
            }   
        }

        return size;
       
    }



     template<typename T>void  LinearList<T> :: fill(const T& item)                       //FUNCTION TO SEARCH THE element
    {   
        
        int i;
        for(i=0;i<size;i++)
            element[i]=item;

    }



     template<typename T>void  LinearList<T> :: erase(const T& item)
    {                                                             //FUNCTION TO DELETE THE element

            for(int i=0;i<size;i++){

                if(element[i] == item)
                {
                    erase_pos(i);
                }

            }
    }

     template<typename T>void LinearList<T> :: erase_pos(const int &pos)
    {                                                             //FUNCTION TO DELETE THE element

        for(int i=pos; i<size-1; i++)
        {   
            
            element[i]=element[i+1];
            
        }   

        size--;
    }


    template<typename T>void  LinearList<T> :: insert(const T& item,const int& k)
    {                                                                                        //INSERTING THE element IN THE LINEAR LIST
         
        int i;

        if(size == capacity){

            resize(2*capacity);
        }
        
        if(k>size)
        {
            element[size]=item;
        }
        else
        {
            for(i=size; i>k; i--)
            {   
            
                element[i]=element[i-1];
            
            }   

            element[k] = item;
        }
         
        size++;        
    }
//}
