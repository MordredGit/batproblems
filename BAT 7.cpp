/*
Names that Do Begin with Vowel- descending order

Given a set of names, design an algorithm and write
 a C++ code to form a sorted list, in the descending
 order of names that do  begin with a vowel.

Hint: Use STL for implementation

Input Format:

Number of names, 'n'

Name 1

Name 2

…

Name n

Output Format:

Names that do  begin with a vowel in a descending  order.
*/

#include <iostream>
#include <string>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>> n;
    cin.ignore();
    vector<string> vowelName;
    list<string> Name;
    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin,s);
        Name.push_back(s);
        switch(s[0])
        {
            case 'a' : case 'A' : case 'e' : case 'E' : case 'i' : case 'I' : case 'o' : case 'O' : case 'u' : case 'U' : vowelName.push_back(s);break;
        }

    }
    sort(vowelName.begin(), vowelName.end());
    for(auto i = vowelName.rbegin(); i != vowelName.rend(); ++i)
        cout<< *i << endl;

}
