#include<iostream>
#include<string>
using namespace std;



int main(int argc, char const *argv[])
{
	string s1,s2;
	cout<<"ENTER 1st STRING: ";
	cin>>s1;
	cout<<"ENTER 2nd STRING: ";
	cin>>s2; 
	if(s1!=s2) cout<<"NOT EQUAL"<<endl;
	else cout<<"EQUAL"<<endl;
	if(s1.compare(s2) == 0) cout<<"EQUAL"<<endl;
	else cout<<"NOT EQUAL"<<endl;

	return 0;
}
