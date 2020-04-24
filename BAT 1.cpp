#include<iostream>
#include <exception>
using namespace std;
#include<string>
template<class T>
class g_Box
{
	int first,mid,last;
	//initially number of elements is 0
	// increment for each insert and
	// decrement for each delete
	int no_Of_Ele;
	//represents maximum number of elements
	// that can be stored
	int capacity;
	T *ele;
	public:
	// allocate memory to store elements and
	// initialize all members
	// let the maximum capacity be 10
	g_Box();
	// parameterised constructor
	// with maximum capacity as parameter
	g_Box(int);
	bool isEmpty();
	bool isFull();
	void insert_First(T);
	void insert_Last(T);
	void insert_Mid(T);
	void delete_First();
	void delete_Last();
	void delete_Mid();
	void print();
};

template<class T>
void shiftToRight(T*,int,int);

template<class T>
void shiftToLeft(T*,int,int);

template<class T>
g_Box<T>::g_Box() : first(-1), mid(-1), last(-1), capacity(10), no_Of_Ele(0)
{
    ele = new T[10];
}

template<class T>
g_Box<T>::g_Box(int cap)
{
    ele = new T[10];
    first = mid = last = -1;
    capacity = cap;
}

template<class T>
bool g_Box<T>::isEmpty()
{
    if(no_Of_Ele == 0) return true;
    else return false;
}

template<class T>
bool g_Box<T>::isFull()
{
    if(no_Of_Ele == capacity) return true;
    else return false;
}

template<class T>
void g_Box<T>::insert_First(T item)
{
    if(isFull()) {cout<< "Full"<< endl; return;}
    if(isEmpty())
    {
        first = mid = last = 0;
        *(ele + first) = item;
    }
    else
    {
        shiftToRight(ele, first, last);
        *(ele + first) = item;
        last++;
        mid = (first + last)/2;
    }
    no_Of_Ele++;
}

template<class T>
void g_Box<T>::insert_Last(T item)
{
    if(isFull()) {cout<< "Full"<< endl; return;}
    if(isEmpty())
    {
        first = mid = last = 0;
        *ele = item;
    }
    else
    {
        last++;
        *(ele + last) = item;
    }
    no_Of_Ele++;
}

template<class T>
void g_Box<T>::insert_Mid(T item)
{
    if(isFull()) {cout<< "Full"<< endl; return;}
    if(isEmpty())
    {
        first = mid = last = 0;
        *ele = item;
    }
    else
    {
        shiftToRight(ele, mid, last);
        *(ele + mid) = item;
        last++;
        mid = (first + last)/2;
    }
    no_Of_Ele++;
}

template<class T>
void shiftToRight(T* elem, int pos, int last)
{
    for(int i = last; i >= pos; i--)
    {
        *(elem + i + 1) = *(elem + i);
    }
}

template<class T>
void g_Box<T>::delete_First()
{
    if(isEmpty()) {cout<< "Empty"<< endl; return;}
    if(no_Of_Ele == 1)
    {
        first = mid = last = -1;
    }
    else
    {
        first++;
        shiftToLeft(ele, first, last);
        first--;
        last--;
        mid = (first + last)/2;
    }
    no_Of_Ele--;
}

template<class T>
void g_Box<T>::delete_Last()
{
    if(isEmpty()) {cout<< "Empty"<< endl; return;}
    if(no_Of_Ele == 1)
    {
        first = mid = last = -1;
    }
    else
    {
        last-- ;
        mid = (first + last)/2;
    }
    no_Of_Ele--;
}

template<class T>
void g_Box<T>::delete_Mid()
{
    if(isEmpty()) {cout<< "Empty"<< endl; return;}
    if(no_Of_Ele == 1)
    {
        first = mid = last = -1;
    }
    else
    {
        mid++;
        shiftToLeft(ele, mid, last);
        last--;
        mid = (first + last)/2;
    }
    no_Of_Ele--;
}

template<class T>
void shiftToLeft(T* elem, int pos, int last)
{
    for(int i = pos; i <= last; i++)
    {
        *(elem + i - 1) = *(elem + i);
    }
}

template<class T>
void g_Box<T>::print()
{
    if(isEmpty()) {cout<< "Box Empty"<< endl; return;}
    for(int i =  first; i <= last; i++)
        cout<< *(ele + i)<< endl;
}

int main()
{
	int d_Choice;
	cin>>d_Choice;
	g_Box<int> g;
	int data;
	g_Box<string> g1;
	string data1;
	if(d_Choice == 1)
	{
	while(1)
	{
	int opt_Choice;
	cin>>opt_Choice;
	if(opt_Choice==1)
	{
	if(g.isEmpty())
	cout<<"Empty"<<endl;
	else
	cout<<"Not empty"<<endl;
	}
	else if(opt_Choice==2)
	{
	if(g.isFull())
	cout<<"Full"<<endl;
	else
	cout<<"Not full"<<endl;
	}
	else if(opt_Choice==3)
	{
	cin>>data;
	g.insert_First(data);
	}
	else if(opt_Choice==4)
	{
	cin>>data;
	g.insert_Last(data);
	}
	else if(opt_Choice==5)
	{
	cin>>data;
	g.insert_Mid(data);
	}
	else if(opt_Choice==6)
	{
	g.delete_First();
	}
	else if(opt_Choice==7)
	{
	g.delete_Last();
	}
	else if(opt_Choice==8)
	{
	g.delete_Mid();
	}
	else if(opt_Choice==9)
	{
	g.print();
	}
	else if(opt_Choice==10)
	{
		break;
	}
	}
	}
	if(d_Choice == 2)
	{
	while(1)
	{
	int opt_Choice;
	cin>>opt_Choice;
	if(opt_Choice==1)
	{
	if(g1.isEmpty())
	cout<<"Empty"<<endl;
	else
	cout<<"Not empty"<<endl;
	}
	else if(opt_Choice==2)
	{
	if(g1.isFull())
	cout<<"Full"<<endl;
	else
	cout<<"Not full"<<endl;
	}
	else if(opt_Choice==3)
	{
	cin>>data1;
	g1.insert_First(data1);
	}
	else if(opt_Choice==4)
	{
	cin>>data1;
	g1.insert_Last(data1);
	}
	else if(opt_Choice==5)
	{
	cin>>data1;
	g1.insert_Mid(data1);
	}
	else if(opt_Choice==6)
	{
	g1.delete_First();
	}
	else if(opt_Choice==7)
	{
	g1.delete_Last();
	}
	else if(opt_Choice==8)
	{
	g1.delete_Mid();
	}
	else if(opt_Choice==9)
	{
	g1.print();
	}
	else if(opt_Choice==10)
	{
		break;
	}
	}
	}
}

/*
Test Case:

1.1
2.1
3.2
4.3   input to first
5.1   array: 1
6.9   display
7.4   input to last
8.2   array: 1 2
9.9   display
10.5  input to mid
11.3  array: 3 1 2
12.9  display
13.6  delete from first
14.7  delete from last
15.9  display
16.8  delete from mid
17.9  display
18.10 exit

Answer:
Empty       1
Not full    2
1           6
1           9
2           9
3           12
1           12
2           12
            15
Box Empty   17

Expected answer:
Empty
Not full
1
1
2
3
1
2
1
Box empty
*/
