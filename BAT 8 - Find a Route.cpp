/*
Find a Route

 Rahul is fond of travelling and he visits cities and towns in the country
 whenever possible. All cities in the country are not connected to each other.
 Given the details of the cities that are connected to each city, source city
 from where he begins the travel and the destination city of the travel, design
 an algorithm and write a C++ code to list down the cities in the travel. Rahul
 must not visit a city more than once. When the destination city name is in the
 connected cities of the current city, chose it and complete the route. When the
 destination city name is not in the list of connected cities to current city
 and there are more than one city from the current city, he sorts the city names
 and include the first minimum city name that is not yet visited. For example,
 if the connection between the cities are given as follows, source city as A
 and destination city as F the list of cities in the travel are A, B, D and F.



City

Connected Cities

A

E, B

B

D

C

E,D

D

F

E

F



Use vectors, maps and algorithms such as sort, find in STL for implementation. Assume
that the connection of cities is very simple and there is a path as described in the
problem.

Input Format

Number of cities that are connected to other cities, 'n'

Name of city1

Number of neighbouring cities for city1, 'm'

First neighbouring city of city1

Second neighbouring city of city1

...

mth neighbouring city of city1

...

Name of cityn

Number of neighbouring cities for cityn, 'm'

First neighbouring city of cityn

Second neighbouring city of cityn

...

mth neighbouring city of cityn



Output Format

Name of cities in the list
*/

//Pre-included code
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<algorithm>
class travel
{
	int num_Of_Cities;
	map<string,vector<string> > city_Connection;
	string source;
	string destn;
	vector<string> route;
	public:
	//In this function form the map that depicts the
	// the connection of cities,key is the name of the
	// city and value is a vector of cities that are
	// connected to the city
	void get();
	void find_Route();
	void print_Route();
};

//My code
void travel::get()
{
    cin>> num_Of_Cities; cin.ignore();
    for(int i = 0; i < num_Of_Cities; i++)
    {
        string cityi;
        vector<string> connCity;
        int numConnCity;
        getline(cin, cityi);
        cin>> numConnCity; cin.ignore();
        for(int j = 0; j < numConnCity; j++)
        {
            string jcity;
            getline(cin, jcity);
            connCity.push_back(jcity);
        }
        if(numConnCity > 1)
        {
            sort(connCity.begin(), connCity.end());
            reverse(connCity.begin(), connCity.end());
        }
        city_Connection.insert(pair<string,vector<string> >(cityi, connCity));
    }
    getline(cin,source);
    getline(cin,destn);
}

void travel::find_Route()
{
    string nextCity;
    nextCity = source;
    while(nextCity != destn)
    {
        route.push_back(nextCity);
        cout<< nextCity<< endl;
        auto con = city_Connection.find(nextCity);
        if(con != city_Connection.end() && (con->second).size() != 0)
        {
            vector<string> Con = con->second;
            string temp = Con.back();
            Con.pop_back();
            city_Connection[nextCity] = Con;
            nextCity = temp;
        }
        else
        {
            route.pop_back();
            nextCity = route.back();
            route.pop_back();
        }
    }
    route.push_back(destn);
}

void travel::print_Route()
{
    for(auto i = route.begin(); i != route.end(); ++i) cout<< *i << endl;
}

//Pre-included code
int main()
{
	travel t;
	t.get();
	t.find_Route();
	t.print_Route();
}

/*
Test Case:

Input
4
A
3
B
C
D
B
1
E
E
2
G
F
F
1
H
A
G
Expected output
A
B
E
G

*/
