#include<bits/stdc++.h>
using namespace std;

bool SubsetSum(int *val, int n , int sum){
	if(n==0 and sum!=0) return false;
	if(sum==0) return true;
	if(sum-val[0]<0) return SubsetSum(val+1,n-1,sum);
	else{
		return SubsetSum(val+1,n-1,sum-val[0]) || SubsetSum(val+1,n-1,sum);
	}
	
}

// bool SubsetSumDP(int *val, int n, int sum){
// 	int**dp = new int[]
// }

bool SubsetSumIt(int* val, int n, int sum){
	bool** dp = new bool*[n+1];
	for(int i = 0 ; i<=n ; i++){
		dp[i] = new bool[sum+1];
	}
	for(int i = 0 ; i<=sum ; i++){
		dp[0][i] = false;
	}
	for(int j = 0 ; j<=n; j++)
		dp[j][0] = true;

	for(int i = 1 ; i<=n ; i++){
		for(int j = 1; j<=sum ; j++ )
		{
			dp[i][j] = dp[i-1][j];
			if(val[i-1]<=j){
				dp[i][j] = dp[i-1][j-val[i-1]] || dp[i][j] ;
			}
		}
	}

		bool ans = dp[n][sum];
		for(int i = 0 ; i<=n ; i++)
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
	cout<<"answer It : "<<SubsetSumIt(val,n,sum)<<endl;
	cout<<"answer : "<<SubsetSum(val,n,sum)<<endl;

	return 0;
}