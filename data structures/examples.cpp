#include<iostream>
#include <algorithm>
#include<vector>
#include<set>
#include<unordered_map>
#include<map>
using namespace std;





int main(int argc, char const *argv[])
{
	int arr[10] = {105,106,111,114,105,135,138,111,147,114};
	// set<int> s;
	// for(int i = 0; i<10; i++) s.insert(arr[i]);
	// vector<int> v;
	// for(auto i = s.begin() ; i!=s.end() ;i++) v.push_back(*i);
	// for(int i = 0 ; i<v.size() ; i++){
	// 	cout<<v[i]<<endl;
	// }

	// set<int> s;
	// vector<int> result;
	// for(int i = 0 ; i<10 ; i++){
	// 	if(s.find(arr[i])==s.end()){
	// 		result.push_back(arr[i]);
	// 		s.insert(arr[i]);
	// 	}
	// }
	// for(int i = 0 ; i<result.size() ; i++){
	// 	cout<<result[i]<<endl;
	// }

	// sort(arr,arr+10);
	// vector<int> answer;
	// answer.push_back(arr[0]);
	// for(int i= 1;  i<10;i++){
	// 	if(arr[i-1]!=arr[i]){
	// 		answer.push_back(arr[i]);
	// 	}
	// }


	// for(int i = 0 ; i<answer.size(); i++){
	// 	cout<<answer[i]<<endl;
	// }


	// second question

	string s;
	cin>>s;

	unordered_map<char,int> frequency;
	for(int i = 0 ; i<s.size() ; i++){
		frequency[s[i]]++;
	}
	string ans;
	for(int i = 0 ; i<s.size() ; i++){
		if(frequency[s[i]]==1){
			ans.push_back(s[i]);
		}
	}
	if(!ans.empty()){
		cout<<ans<<endl;
	}
	else cout<<s[0]<<endl;
	
	

	return 0;
}