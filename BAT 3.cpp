/*
How to Serve a Coffee?


Jegan organizes a family function and invite some of his friends. Many
of his friends come prior to the function. Jegan has arranged for their
accommodation in a hotel. The rooms are booked as the guest arrive, so
the room numbers are not continous and not in any order. Jegan has the
room number of the friend who had arrived first. And he has requested
his friends to have a room number of the person who arrives next to him.
That is the friend who arrived third will have room number of the friend
who arrived fourth. The last guest will not have any room number. Given
the details of each guest such as name, his room number and room number
of the guest who arrived next, and room number of that Jegan has, design
an algorithm and write a C++ code to print the names and room numbers to
serve a coffee. For example, if the details in the following table is given



Room Number of Guest    Name of Guest   Room number the guest who arrived next

125                     John            210

157                     Kannan          125

210                     Kumar           -1

315                     Anand           157



If Jegan has room number as 315, room number of the friend who arrived first, then the output should be

Anand 315

Kannan 157

John 125

Kumar 210

Hint: Map in STL can be used for representing the input, room number
of the guest may be the key and other two details may be stored as value
by representing them as a user defined data type.

Input Format

Number of friends

Room number of guest1

Name of guest1

Room number the guest who arrived next to guest1

Room number of guest2

Name of guest2

Room number the guest who arrived next to guest2

....

Room number of guestn

Name of guestn

-1 ( Last guest doesn't posses any room number)

Room number that Jegan has

Output Format

Name of guest1 and his Room number separated by tab

Name of guest2 and his Room number separated by tab

...

Name of guestn and his Room number separated by tab
*/

#include<iostream>
using namespace std;
#include<string>
#include<map>
struct guest
{
	int room_No;
	string name;
	int friend_Room_No;
	public:
	void get();
};
class hotel
{
	int num_Of_Guest;
	map<int,guest> stay_Det;
	//this room number is with jegan
	int first_Room_No;
	public:
	void get();
	//this function should print
	//details such as name and room number
	// of guest to serve coffee
	void serve_Coffee();
};

void guest::get()
{
    cin>> room_No;
    cin.ignore();
    getline(cin, name);
    cin>> friend_Room_No;
}

void hotel::get()
{
    int noOfFriends;
    cin>> noOfFriends;
    for(int i = 0; i < noOfFriends; i++)
    {
        guest Guest;
        Guest.get();
        stay_Det.insert(pair<int,guest>(Guest.room_No,Guest));
    }
    cin >> first_Room_No;
}

void hotel::serve_Coffee()
{
    int i = first_Room_No;
    while(i != -1)
    {
        auto found = stay_Det.find(i);
        cout<< (found->second).name << "\t" << i<< endl;
        i = (found->second).friend_Room_No;
    }
}


main()
{
	hotel h;
	h.get();
	h.serve_Coffee();
}
