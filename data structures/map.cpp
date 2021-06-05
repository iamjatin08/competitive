#include <iostream>
#include<vector>
#include<utility>
#include<string>
#include<set>
#include <map>
#include<unordered_map>
#include<unordered_set>
using namespace std;



int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,5};
	map<int,int> m;
	for(int i = 0 ; i<7 ; i++){
		m[arr[i]]++;
	}	
	map<int,int> :: iterator it = m.begin();
	for(;it!=m.end() ; it++){
		// cout<<(*it).first<<" : "<<(*it).second<<endl;
		cout<<(it)->first<<" : "<<(it)->second<<endl;

	}
	m.erase(5);
	if(m.find(5)==m.end()){
		cout<<"KEY NOT FOUND"<<endl;
	}
	else{
		cout<<"KEY FOUND"<<endl;
	}
	return 0;
}