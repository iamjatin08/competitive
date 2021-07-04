#include <bits/stdc++.h>
using namespace std;

int minHealth(int **input , int m, int n){
	int **dp = new int*[m];
	for(int i = 0 ; i<m ; i++){
		dp[i] = new int[n];
	}
	dp[m-1][n-1] = input[m-1][n-1];
	for(int i = m-2 ; i>=0 ; i--){
		dp[i][n-1] = dp[i+1][n-1] + input[i][n-1];
	}
	for(int j = n-2 ; j>=0 ; j--){
		dp[m-1][j] = dp[m-1][j+1] + input[m-1][j];
	}
	for(int i = m-2 ; i>=0 ; i--){
		for(int j = n-1 ; j>=0 ; j--){
			int rightHealth = dp[i+1][j];
			int bottomHealth = dp[i][j+1];
			// for right health
			if(input[i+1][j]<0){
				rightHealth+=(-1)*input[i+1][j];
			}
			else if(rightHealth<=input[i+1][j]){
				rightHealth = 1;
			}
			else{
				rightHealth-=input[i+1][j];

			}
			//bottom Health
			if(input[i][j+1]<0){
				bottomHealth+=(-1)*input[i][j+1];
			}
			else if(bottomHealth<=input[i][j+1]){
				bottomHealth = 1;
			}
			else{
				bottomHealth-=input[i][j+1];

			}
			dp[i][j] = max(rightHealth,bottomHealth);
		}
	}
	int ans = dp[0][0];
	for(int i = 0 ; i<m ; i++) delete [] dp[i];
	delete [] dp;
	return ans;
}


int main(int argc, char const *argv[])
{
	int m ,n;
	cout<<"ENTER ROW : ";
	cin>>m;
	cout<<"ENTER COL : ";
	cin>>n;
	int **input = new int*[n];
	cout<<"ENTER VALUES"<<endl;
	for(int i = 0 ; i<m ;i++)
	{
		input[i] = new int[n];
		for(int j = 0 ; j<n ; j++) cin>>input[i][j];
	}	
	cout<<"ANS : "<<minHealth(input,m,n)<<endl;
	for(int i = 0 ; i<m ; i++){
		delete []  input[i];
	}
	delete [] input;
	return 0;
}