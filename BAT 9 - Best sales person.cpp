/*
Best sales person
A company stores the name, age and sales made in five cities of their salespersons,
given the details of ‘n’ employees, write an algorithm and the C program to find the
best sales person. Best sales person is the one who has made maximum sales in the
company. For example given the details of six salespersons with the following details:



SP1, 34, 45, 18, 22, 38, 37

SP2, 32, 46, 15, 23, 35, 29

SP3, 29, 47, 16, 30, 35, 35

SP4, 31, 49, 12, 32, 36, 40

SP5, 23, 45, 11, 30, 35, 39

SP6, 29, 41, 15, 31, 33, 37



Then the best salesperson is SP4.



Input Format

First line contains the number of salespersons, n

Next n lines contain the details of ‘n’ salespersons such as name, age and sales made by the salesperson in five cities separated by space
*/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>> n;
    vector<vector<string>> Salesmen;
    cin.ignore();
    for(int i = 0;i < n;i++)
    {
        vector<string> salesman;
        string input = "";
        getline(cin, input);
        input.push_back(' ');
        int c = 0;
        for(int i = 0; i != input.length(); i++)
        {
            if(input.at(i) == ' ')
            {
                string word = input.substr(c, i - c);
                salesman.push_back(word);
                c = i + 1;
            }
        }
        Salesmen.push_back(salesman);
    }

    int bestSales = 0;
    auto Best = Salesmen.begin();
    for(auto i = Salesmen.begin(); i != Salesmen.end(); ++i)
    {
        int sal = 0;
        for(int j = 2; j < 7; j++)
            sal += stoi((*i).at(j));
        if(sal > bestSales)
        {
            bestSales = sal;
            Best = i;
        }
    }
    cout<< (*Best).at(0);
}


/*
Test Cases:
Input
6
SP1 34 45 18 22 38 37
SP2 32 46 15 23 35 29
SP3 29 47 16 30 35 35
SP4 31 49 12 32 36 40
SP5 23 45 11 30 35 39
SP6 29 41 15 31 33 37
Expected output
SP4
*/
