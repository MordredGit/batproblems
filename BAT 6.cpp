/*
Arrange Items for Solar Vehicle
There are 'n' bags in a corner of a city and they have to be moved to the centre
of the city by a solar vehicle. The vehicle starts shunting from morning, the
vehicle can carry more load in the mornings than in the evening when sunlight
would be dimmer. Given the details of items in the bag, sort the bag in descending
so that the vehicle can safely carry it to the centre of the city. Use vector
and map in STL. Also use the sort algorithm defined in STL.



Hint: Use total weight of bag as key and object of bag as value, insert total
weight of each bag into a vector. Use STL sort algorithm to sort it and print
the details of bag in order



Input Format

Number of bags 'n'

Name of bag1

Number of types of items in bag1, 't'

Weight of item1 in bag1

Number of item1 in bag1

Weight of item2 in bag1

Number of item2 in bag1

...

Weight of itemt in bag1

Number of itemt in bag1

...

....

....

Name of bagn

Number of types of items in bagn, 't'

Weight of item1 in bagn

Number of item1 in bagn

Weight of item2 in bagn

Number of item2 in bagn

...

Weight of itemt in bagn

Number of itemt in bagn

Output Format

Print name of bags in sorted order.

Sorting must be done in descending order based on the weight of the bag
*/

#include <iostream>
#include<map>
#include <vector>
#include <algorithm>
using namespace std;
class bag
{
	char name[30];
	int num_Of_Items;
	float item_Wt[20];
	float item_Count[20];
	public:
	void get();
	//print only name of bag
	void print();
	//Compute weight from details given
	float compute();
};
bool wayToSort(int i, int j);
class solar
{
	map<float,bag> m1;
	vector<float> v;
	int num_Bags;
	public:
	//get details of bags and insert into map and vector
	// In map, key - weight and value - details of bag
	// In vector, weight of bags
	void get();
	void sort_Vec();
	//print name of bags in sorted order
	void print_In_Order();
};

void bag::get()
{
    cin.ignore();
    cin.getline(name, 30);
    cin>> num_Of_Items;
    for(int i = 0; i < num_Of_Items;i++)
    {
        cin>> item_Wt[i]>> item_Count[i];
    }
}

void bag::print()
{
    cout<< name<< endl;
}

float bag::compute()
{
    float weight;
    for(int i = 0; i < num_Of_Items; i++)
    {
        weight += item_Wt[i] * item_Count[i];
    }
    return weight;
}

void solar::get()
{
    cin>> num_Bags;
    for(int i = 0; i < num_Bags; i++)
    {
        bag Bag;
        Bag.get();
        float weight = Bag.compute();
        m1.insert(pair<float,bag>(weight, Bag));
        v.push_back(weight);
    }
}

void solar::sort_Vec()
{
    sort(v.begin(), v.end());
}

void solar::print_In_Order()
{
    for(auto i = v.rbegin(); i != v.rend(); ++i)
    {
        auto found = m1.find( *i );
        (found->second).print();
    }
}

int main()
{
	solar s;
	s.get();
	s.sort_Vec();
	s.print_In_Order();
}

