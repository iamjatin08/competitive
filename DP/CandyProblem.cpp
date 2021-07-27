#include <bits/stdc++.h>
using namespace std;

long long solve(int like[3][3], int N){

	long long dp[1<<N] = {0};
	
	dp[(1<<N)-1] = 1;

	for(int mask = (1<<N)-2 ; mask>=0 ; mask--){

		// count set bits
		int temp = mask;
		int k = 0 ;
		while(temp>0){
			int lastbit = temp&1;
			k = k+ lastbit;
			temp/=2;
		}
		for(int i = 0 ; i<N; i++){
			if(like[k][i] and !(mask&(1<<i))){
				dp[mask] += dp[mask | (1<<i)];
			}
		}
	}

	return dp[0];
}

int main(int argc, char const *argv[])
{
	int like[3][3] = {{1,1,1},{1,0,1},{1,1,1}};

	cout<<solve(like,3)<<endl;


	return 0;
}