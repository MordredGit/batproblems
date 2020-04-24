/*
3-D points- multiply and increment

Given a point in three-dimensional space with x-coordinate,
y-coordinate, z-coordinates,  Provide a function increment
with one, two and three parameters to transform  the values
of all the three coordinates. When the function with one
parameter is called increment all the three , by same value .
When the function with two arguments is called multiply each
coordinates by the sum  of the two parameters. when the function
with three arguments is called, increment x-coordinate  by
the value of first parameter, y-coordinate by the value of
the second parameter and z-coordinate  by the value of the
third parameter.

Input format:

Enter the coordinates of the point

X-coordinate

Y-coordinate

Z-coordinate

Enter the increment value for function with one parameter

Enter the values for the function with two parameters

Enter the  increment values for function with three parameters

Output format:

Display the coordinates of the point after calling function with one parameter

Display the coordinates of the point after calling function with two parameters

Display the coordinates of the point after calling function with three parameters
*/

#include<iostream>

using namespace std;

class dim
{
    int x, y, z;
public:
    void increment(int);
    void increment(int,int);
    void increment(int,int,int);
    void get();
    void print();

};

void dim::get()
{
    cin>>x>>y>>z;
}

void dim::increment(int a)
{
    x += a; y += a; z += a;
}

void dim::increment(int a, int b)
{
    x *= a+b; y *= a+b; z *= a+b;
}

void dim::increment(int a, int b, int c)
{
    x += a; y += b; z += c;
}

void dim::print()
{
    cout<<x<<y<<z<<endl;
}

main()
{
	dim d1;
	d1.get();
	int inc;
	cin>>inc;
	int p1,p2;
	cin>>p1>>p2;
	int ix,iy,iz;
	cin>>ix>>iy>>iz;
	d1.increment(inc);
	d1.print();
	d1.increment(p1,p2);
	d1.print();
	d1.increment(ix,iy,iz);
	d1.print();
}
