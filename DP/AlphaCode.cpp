#include<bits/stdc++.h>
using namespace std;



int AlphaCode(int *n, int size, int * dp){
	if(size == 1  or size == 0) return 1;
	if(dp[size]!=0) return dp[size];
	int output = AlphaCode(n,size-1,dp);
	if((n[size-2]*10)+n[size-1]<=26){
		output+=AlphaCode(n,size-2,dp);
	} 
	dp[size] = output;

	return output;
}

int AlphaCode(int *n , int size ){
	int * dp = new int[size+1];
	memset(dp,0,(size+1)*sizeof(int));
	int ans = AlphaCode(n,size,dp);
	delete [] dp;
	return ans;
}


int AlphaCode2(int *n , int size){
	int * output = new int[size+1];
	output[0] = 1;
	output[1] = 1;
	for(int i = 2; i<=size ; i++){
		int ans = output[i-1];
		if(((n[i-2]*10)+n[i-1])<=26){
			ans+=output[i-2];
		}
		output[i] = ans;
	}
	int ans = output[size];
	delete [] output;
	return ans;
}

int main(int argc, char const *argv[])
{
	int size;
	cout<<"SIZE : ";
	cin>>size;
	int *n = new int[size];
	cout<<"ENTER NUMBER : ";
	for(int i = 0 ; i<size ; i++) 
		cin>>n[i];
	cout<<AlphaCode(n,size)<<endl;
	cout<<AlphaCode2(n,size)<<endl;
	delete [] n;
	return 0;
}