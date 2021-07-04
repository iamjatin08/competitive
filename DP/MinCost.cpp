#include<bits/stdc++.h>
using namespace std;

int MinCost(int ** input ,int sr , int sc , int er, int ec){
	if(sr==er and sc == ec) {
		return input[er][ec];
	}
	
	if(sr>er or sc>ec) return INT_MAX;

	int ans1 = MinCost(input,sr+1,sc,er,ec);
	int ans2 = MinCost(input,sr+1,sc+1,er,ec);
	int ans3 = MinCost(input,sr,sc+1,er,ec);
	int ans = min(ans1,min(ans2,ans3)) + input[sr][sc];
	return ans;

}

// pure DP
int min_cost_dp(int** input, int m , int n){
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
		for(int j = n-2 ; j>=0 ; j--){
			dp[i][j] = min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1])) + input[i][j];
		}
	}
	int ans = dp[0][0];
	for(int i = 0 ; i<n ; i++) delete []  dp[i];
	delete [] dp;	
	return ans;
}

int main(int argc, char const *argv[])
{
	int ** input = new int*[3];
	input[0] = new int[3];
	input[1] = new int[3];
	input[2] = new int[3];

	input[0][0] = 4; 
	input[0][1] = 3; 
	input[0][2] = 2; 
	input[1][0] = 1; 
	input[1][1] = 8; 
	input[1][2] = 3; 
	input[2][0] = 1; 
	input[2][1] = 1; 
	input[2][2] = 8; 
	cout<<MinCost(input,0,0,2,2)<<endl;
	cout<<min_cost_dp(input,3,3)<<endl;
	return 0;
}