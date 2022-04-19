#include<iostream>
using namespace std;
class array
{
    private:
 	
 	int size;    //total capcity of the list
 	int length;   //number of current elements in the list
 	int arraysize;
 	int pos;
 	int *curr;
 	int *arr;  //will be used to initialize an empty list
 	int *data;
 	void DoubleArraySize();
    
    public:
    	array()                    //constructor 
		{
    		size=10;
    		length=0;
    		*curr;
    		*arr;
    		*data;
    		arr=new int[size];
    		
    }
    		
    		~array(){                    //destructor
    			delete []arr;
			}
    		
	void printArray(){
		int *ptr=arr;
		for (int x=0; x<size; x++)
		cout <<*ptr++<<"\t";
	
	}
	int search(int x){
		 for (int i = 0; i < size; i++)
   {
       if (data[i] == x)
           return i;
   }
   return -1;
	
	}
	void insert(int x){
		if (size >= arraysize)
       DoubleArraySize();
    data[size++] = x;
	}

	void insert(int val,int pos){
		for (int i = length; i >= pos ;i--)
		{
			*(curr+1)=*curr;
			curr--;
		}
		*(curr+1 )= val;
		length++;
	}
		bool deleteElement( int x)
	{
		int index = search(x);
        if (index != -1)
   {
       for (int i = index + 1; i < size; i++)
       {
           data[i - 1] = data[i];
       }
      
       size++;           //delete element
       return true;
   }
   else
   {
       return false;
   }
}
	bool isEmpty()
	{
		if(length==0 )
		{
			return true;
		}
	}
	 
	bool isfull()
	{
		if( length ==size)
		{
			return true ;
		}
	}
	void reverseList()
{
   int *newData = new int[size];
   for (int i = 0, j = size - 1; i < size; i++, j--)
   {
       newData[j] = data[i];
   }
   delete[] data;
   data = newData;
}
	void emptyList()
{
   size = 0;
   arraysize = 2;
   delete[] data;
   data = new int[arraysize];
}
    void copyList(array ll)
{
   size = ll.size;;
   arraysize = ll.arraysize;
   data = new int[arraysize];
   data=ll.data;
}
void printList()
{
   if (!isEmpty())
   {
       cout << "ListADT Elements: ";
       for (int i = 0; i < size; i++)
           cout << data[i] << " ";
       cout << endl;
   }
   else
   {
       cout << "No elements in Arrray List" << endl;
   }
}
    



};

int main()
{
   array a;
   char ch;
   int temp;
   int index;

while (true)
   {
       cout << "1.insert data" << endl;
       cout << "2.delete data" << endl;
       cout << "3.reverseList " << endl;
       cout << "4.printList" << endl;
       cout <<" 5.emptyList" << endl;
       cout << "6. exist" << endl;
       cout << "Enter your choice: ";
       cin >> ch;
       switch (ch)
       {
       case '1':
           cout << "Enter data to insert: ";
           cin >> temp;
           a.insert(temp);
           break;
       case '2':
           cout << "Enter data to delete: ";
           cin >> temp;
           if (a.deleteElement(temp))
               cout << temp << " first occurence is deleted from array";
           else
               cout << temp << " not found / invalid ";
           cout << endl;
           break;
       case '3':
           a.reverseList();
           cout << "After Reversing: " << endl;
           a.printList();
           break;
       case '4':
           a.printList();
           break;
       case '5':
           a.emptyList();
           cout << "all  elements are deleteElementd from array" << endl;
           break;
       case '6':
           exit(1);
       default:
           cout << "InvalidChoice";
           break;
       }
   }
}
 
