#include <iostream>
#include<vector>
#include<utility>
#include<string>
#include<set>
using namespace std;



int main(int argc, char const *argv[])
{
	set<int> s;
	int arr[] = {1,2,3,4,5,6,5};
	for(int i = 0; i<7 ;i++){
		s.insert(arr[i]);
	}
	set<int>::iterator it = s.begin();
	for(;it!=s.end() ; it++){
		cout<<*it<<endl;
	}
	if(s.find(6) == s.end()){
		cout<<"ELEMENT NOT FOUND"<<endl;
	}
	else{
		cout<<"ELEMENT FOUND"<<endl;
	}

	return 0;
}