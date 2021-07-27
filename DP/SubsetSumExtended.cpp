#include<bits/stdc++.h>
using namespace std;

bool SubsetSumItExtended(int* val, int n, int sum){
	bool** dp = new bool*[2];
	for(int i = 0 ; i<=1 ; i++){
		dp[i] = new bool[sum+1];
	}
	for(int i = 0 ; i<=sum ; i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag  = 1;


	for(int i = 1 ; i<=n ; i++){
		for(int j = 1; j<=sum ; j++ )
		{
			dp[flag][j] = dp[flag^1][j];
			if(val[i-1]<=j){
				dp[flag][j] = dp[flag^1][j-val[i-1]] || dp[flag][j] ;
			}
		}
		flag = flag^1;
	}

		bool ans = dp[flag^1][sum];
		for(int i = 0 ; i<=1 ; i++)
			delete [] dp;
		delete  [] dp;
		return ans;
		
}



int main(int argc, char const *argv[])
{
	int val[10];
	cout<<"n : ";
	int n;
	cin>>n;
	cout<<"VALUES : ";
	for(int i = 0 ; i<n ; i++)
		cin>>val[i];
	int sum ;
	cout<<"SUM : ";
	cin>>sum;
	cout<<"answer It Extended : "<<SubsetSumItExtended(val,n,sum)<<endl;
	

	return 0;
}