#include<bits/stdc++.h>
using namespace std;

int fib(int n,int *dp){
	if(n==0  or n == 1) return 1;
	if(dp[n]!=0) return dp[n];
	dp[n] = fib(n-1,dp)+fib(n-2,dp);
	return dp[n];
}

int fib(int n){
	int * dp = new int[n+1];
	memset(dp,0,n+1*sizeof(int));
	dp[0] = 1;
	dp[1] = 1;
	int ans = fib(n,dp);
	delete [] dp;
	return  ans;
}

int fib2(int n){
	int *arr = new int [n+1];
	 arr[0] = 1;
	 arr[1] = 1;
	 for(int i = 2;  i<=n ; i++){
	 	arr[i] = arr[i-1]+arr[i-2];
	 }
	 int ans = arr[n];
	 delete []  arr;
	 return ans;
}




int main(int argc, char const *argv[])
{
	int n ;
	cin>>n;
	cout<<fib(n)<<endl;
	cout<<fib2(n)<<endl;
	// int * ans = new int[n];

	return 0;
}