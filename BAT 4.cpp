/*
Function to convert to Qudadecimal

A Quadadecimal number system is a hypothetical number system
with base 14. The digits of the number system are 0, 1, 2, 3,
4, 5, 6, 7, 8, 9, A, B, C, D. A decimal number ‘x’ can be
converted to quadadecimal number by dividing it repeatedly by
14. The reminders obtained during division put together in
reverse order form the quadadecimal equivalen of ‘x’. Decimal
number 82 is converted to its quadadecimal equivalent (5C ) as
follows:

14  |  82 - C
    |  5

Input Format

First line contains the number n, in decimal number system



Output Format

Print the quadadecimal equivalent of number, n
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int N;
    string QN = "" ;
    cin>> N;
    while(N > 0)
    {
        int rem = N%14;
        if(rem < 10) QN = to_string(rem) + QN;
        else if(rem == 10) QN = "A" + QN;
        else if(rem == 11) QN = "B" + QN;
        else if(rem == 12) QN = "C" + QN;
        else if(rem == 13) QN = "D" + QN;
        N /= 14;
    }
    cout<< QN;
}
