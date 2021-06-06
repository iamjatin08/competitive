#include<iostream>
#include <algorithm>
#include <math.h>
using namespace std;




int main(int argc, char const *argv[])
{
	cout<<"GCD: "<<__gcd(10,6)<<endl;
	cout<<"POWER: "<<pow(3,10)<<endl;


	int x = 10;
	int y = 12;
	swap(x,y);
	cout<<"x: "<<x<<" y: "<<y<<endl;
	cout<<"MAX: "<<max(x,y)<<endl;
	return 0;
}