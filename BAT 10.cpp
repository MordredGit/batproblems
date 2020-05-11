/*
Generic Double Ended Queue

Design a generic class queue to maintain a list of elements. Queue is a linear
data structure that follow FIFO ordering of elements. It is a special kind of
list where elements can be inserted at one end and deleted at the end. There
are two end points called front and rear. Front is the point of deletion and
that move for each deletion but always points to the element that was inserted
first among the elements remaining in the queue. Rear is the point of the
insertion and move for each insertion but always points to the element that was
inserted last among the elements remaining in the queue. Provide member
functions to check if a queue is empty, queue is full, enqueue and dequeue.



Enqueue - if queue is not full, increment rear and place the element

dequeue – If queue is not empty, return element pointed by front and increment front

isempty – Return true when front is greater than rear or when both are -1

isfull – return true when rear is capacity - 1



Extended the class queue to create another generic class deque which represents a
double ended queue. In deque, elements can be added to or removed from either the
front or rear. The operations in a deque are defined as follows:



push_back – Insert an element at the rear (enqeue in Queue)

push_front – Insert an element at the front, if queue is not full push all elements
forward and place new element, change rear also

pop_back – Remove an element at the rear, if queue is not empty, return element
pointed by rear and decrement rear

pop_front – Remove an element at the front (dequeue in Queue)

print - print elements of queue from first to last

Input Format

Choice of queue and data type (1 – integer linear queue, 2 – String deque)

Choice of operation

For queue – 1 – isempty, 2 – isfull, 3 – enqueue, 4 – dequeue, 5 – Print content of queue, 6 - exit

for enqueue option 3, element to be inserted will follow the choice

For deque – 1 – isempty, 2 – isfull, 3 – push_back, 4 – push_front, 5 – pop_back, 6 – pop_front 7 – Print content of deque, 8 - exit

for both the push options 3 and 4, element to be inserted will follow the choice

Output Format

Print the content of queue after each operation, print elements from first to last
*/

#include<iostream>
using namespace std;
#include<string>
//global error flag for dequeue
bool ERR_Flag = false;
template<class T>
class queue
{
	protected:
        int front;
        int rear;
        int capacity;
        T *ele;
	public:
        //constructor to allocate memory and initialize data members
        queue();
        bool isempty();
        bool isfull();
        //Check if queue is full before insertion
        //if queue is full return false
        // insert element and return true otherwise
        bool enqueue(T data);
        //funtion to remove an element and return
        T dequeue();
        ~queue();
        void print();
};
template<class T>
class deque:public queue<T>
{
	public:
        bool push_Back(T data);
        bool push_Front(T data);
        T pop_Front();
        T pop_Back();
};


//Code here
template<class T>
queue<T>::queue(): front(-1), rear(-1), capacity(20)
{
    ele = new T[20];
    for(int i = 0; i < capacity; i++) *(ele + i) = -1;
}

template<class T>
bool queue<T>::isempty()
{
    if(rear == -1) return true;
    return false;
}

template<class T>
bool queue<T>::isfull()
{
    if(rear == capacity - 1) return true;
    return false;
}

template<class T>
bool queue<T>::enqueue(T data)
{
    if(isfull()) return false;
    else
    {
        if(isempty()) front++;
        rear++;
        *(ele + rear) = data;
        return true;
    }
}

template<class T>
T queue<T>::dequeue()
{
    if(isempty())
    {
        ERR_Flag = true;
        return NULL;
    }
    else if(front == rear)
    {
        T temp = *(ele + front);
        front = rear = -1;
        return temp;
    }
    else
    {
        T temp = *(ele + front);
        front++;
        return temp;
    }
}

template<class T>
void queue<T>::print()
{
    if(isempty()) return;
    for(int i = front; i <= rear; i++) cout<< *(ele + i)<< endl;
}

template<class T>
queue<T>::~queue()
{
    delete ele;
}

template<class T>
bool deque<T>::push_Back(T data)
{
    return this->enqueue(data);
}

template<class T>
bool deque<T>::push_Front(T data)
{
    if(this->isempty() || this->isfull()) return this->enqueue(data);
    else
    {
        int p = this->rear;
        while(p >= this->front)
        {
            *(this->ele + p + 1) = *(this->ele + p);
            p--;
        }
        *(this->ele + this->front) = data;
        this->rear++;
        return true;
    }
}

template<class T>
T deque<T>::pop_Front()
{
    return this->dequeue();
}

template<class T>
T deque<T>::pop_Back()
{
    if((this->isempty()) || (this->front == this->rear)) return this->dequeue();
    else
    {
        T data = *(this->ele + this->rear);
        this->rear--;
        return data;
    }
}


int main()
{
	int d_Choice;
	int op_Choice;
	deque<string> d;
	queue<int> q;
	cin>>d_Choice;
	if(d_Choice==1)
	{
		while(1)
		{
			cin>>op_Choice;
			if(op_Choice==1)
			{
				if(q.isempty())
				cout<<"Queue is empty"<<endl;
				else
				cout<<"Queue is not empty"<<endl;
			}
			else if(op_Choice==2)
			{
				if(q.isfull())
				cout<<"Queue is full"<<endl;
				else
				cout<<"Queue is not full"<<endl;
			}
			else if(op_Choice==3)
			{
				int data;
				cin>>data;
				if(!q.enqueue(data))
				cout<<"Queue full insertion not possible";
			}
			else if(op_Choice==4)
			{
				q.dequeue();
				if(ERR_Flag)
				cout<<"Queue is empty";
			}
			else if(op_Choice==5)
			{
				q.print();
			}
			else if(op_Choice==6)
			{
			break;
			}
		}
	}
	else if(d_Choice==2)
	{
		string s_Data;
		while(1)
		{
			cin>>op_Choice;
			if(op_Choice==1)
			{
				if(d.isempty())
				cout<<"Queue is empty"<<endl;
				else
				cout<<"Queue is not empty"<<endl;
			}
			else if(op_Choice==2)
			{
				if(d.isfull())
				cout<<"Queue is full"<<endl;
				else
				cout<<"Queue is not full"<<endl;
			}
			else if(op_Choice==3)
			{
				cin>>s_Data;
				if(!d.push_Back(s_Data))
				cout<<"Queue full insertion not possible";
			}
			else if(op_Choice==4)
			{
				cin>>s_Data;
				if(!d.push_Front(s_Data))
				cout<<"Queue full insertion not possible";

			}
			else if(op_Choice==5)
			{
				d.pop_Back();
				if(ERR_Flag)
				cout<<"Queue is empty";
			}
			else if(op_Choice==6)
			{
				d.pop_Front();
				if(ERR_Flag)
				cout<<"Queue is empty";
			}
			else if(op_Choice==7)
			{
				d.print();
			}
			else if(op_Choice==8)
			{
				break;
			}
		}
	}
}

/*
Test case:
Input:
1
1
2
3
1
5
3
2
5
4
5
4
5
6
Expected output:
Queue is empty
Queue is not full
1
1
2
2

Input
2
3
abc
7
4
def
7
5
7
6
7
8
Expected output
abc
def
abc
def
Queue is empty
*/
