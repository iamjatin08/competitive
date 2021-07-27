#include<bits/stdc++.h>
using namespace std;

int lcs(char* s1, char* s2){
	if(s1[0]=='\0' || s2[0]=='\0'){
		return 0;
	}	
	if(s1[0]==s2[0]){
		return 1+lcs(s1 + 1,s2 + 1);
	}
	else{
		int opt1 = lcs(s1,s2+1);
		int opt2 = lcs(s1+1,s2);
		return max(opt1,opt2);
	}
}

int lcsHelper(char* s1, char* s2, int m , int n, int**dp){
	if(m==0 or n==0) return 0;
	if(dp[m][n]>-1) return dp[m][n];
	int ans;
	if(s1[0]==s2[0]){
		ans = lcsHelper(s1+1,s2+1,m-1,n-1,dp)+1;
		
	}
	else{
		int opt1 = lcsHelper(s1+1,s2,m-1,n,dp);
		int opt2 = lcsHelper(s1,s2+1,m,n-1,dp);
		ans  = max(opt1,opt2);
		
	}
	dp[m][n] = ans;
	return ans;
}

int lcsDP(char* s1,char*s2){
	int m = strlen(s1);
	int n = strlen(s2);
	int** dp = new int*[m+1];
	for(int i = 0 ; i<=m ;i++){
		dp[i] = new int[n+1];
		for(int j = 0 ; j<=n ; j++)
			dp[i][j] = -1;
	}

	int ans = lcsHelper(s1,s2,m,n,dp);
	for(int i = 0 ; i<= m ; i++)
		delete [] dp[i];
	delete [] dp;
	return ans;


}

int main(int argc, char const *argv[])
{
	char a[100];
	char b[100];
	cin>>a>>b;
	cout<<lcsDP(a,b)<<endl;
	cout<<lcs(a,b)<<endl;
	return 0;
}