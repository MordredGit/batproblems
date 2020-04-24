/*
Count the Number of Items

Given a collection of elements and a value specifying a value to be checked,
develop a generic function count the number of elements with the value. Use
the function to check a collection of primitive data types such as integers,
floating point values and characters. Also given a set of books in a library
and the name of the book to be searched, use the generic function to count
the number of books in the library with the given name. Use predefined string
class for representing name of the book, '==' operator is overloaded in
predefined class string to check if two strings are same.

Input Format:

Choice of type of input (0- int, 1 – char, 2- book)

The first line will contain the number of elements ‘n’

The next ‘n’ lines will contain the details of each element

If the elements are of type book then the order of details are:

book id, book name, author name and cost

Element to be searched

Output Format:

Count of elements in the collection
*/

#include<iostream>
#include <exception>
using namespace std;
#include<string>
//Collection of data in which search has to be made
//and data to be searched may be different
//so have two template class variables
template<class T,class S>
int count(T *data,int size, S search);
class book
{
	int id;
	string name;
	string a_Name;
	float price;
	public:
	void get();
	// overload the '==' operator to check if
	// name of book is same as the string passed
	//return true if it is same
	bool operator==(string);
};

bool book:: operator == (string item)
{
    if(name.compare(item) == 0) return true;
    else return false;
}

void book::get()
{
    cin>>id;
    cin.ignore();
    getline(cin, name);
    cin.ignore();
    getline(cin, a_Name);
    cin>>price;
}
template<class T,class S>
int count(T *data,int size, S search)
{
    int c = 0;
        for(int i = 0;i < size; i++)
        {
            if(*(data + i) == search) c++;
        }
    return c;
}

template<>
int count(book *data,int size, string search)
{
    int c = 0;
        for(int i = 0;i < size; i++)
        {
            if(*(data + i) == search) c++;
        }
    return c;
}

int main()
{

    int choice, n;
    cin>> choice>> n;

    switch(choice)
    {
        case 0:
            {
                int data[n], search;
                for(int i = 0;i < n;i++)
                {
                    cin>>data[i];
                }
                cin>>search;
                cout<<count<int,int>(data, n, search);
                break;
            }
        case 1:
            {
                char data[n], search;
                for(int i = 0;i < n;i++)
                {
                    cin>>data[i];
                }
                cin>>search;
                cout<<count<char,char>(data, n, search);
                break;
            }
        case 2:
            {
                book data[n]; string search;
                for(int i = 0;i < n;i++)
                {
                    data[i].get();
                }
                cin>>search;
                cout<<count<book,string>(data, n, search);
                break;
            }
    }

}
