#include <iostream>
#include<vector>
#include<utility>
#include<string>
using namespace std;






int main(int argc, char const *argv[])
{
	pair<int,char> p;
	p = make_pair(3,'c'); // to make pair after declaration 
	cout<<p.first<<" "<<p.second<<endl;

	pair<int,char> p2(1,'a');
	cout<<p2.first<<" "<<p2.second<<endl;

	return 0;
}