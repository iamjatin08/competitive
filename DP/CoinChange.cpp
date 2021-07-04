#include <bits/stdc++.h>
using namespace std;


int CoinChange(int n, int * d, int numD){
	if(n==0) return 1;
	if(n<0) return 0;
	if(numD == 0 ) return 0;

	int first = CoinChange(n-d[0],d,numD);
	int second = CoinChange(n,d+1,numD-1);
	return first + second;
}

int CoinChange2(int n, int * d, int numD , int ** output){
	if(n==0) return 1;
	if(n<0) return 0;
	if(numD == 0 ) return 0;
	if(output[n][numD] > -1) return output[n][numD];
	int first = CoinChange(n-d[0],d,numD);
	int second = CoinChange(n,d+1,numD-1);
	output[n][numD] = first + second;
	return output[n][numD];
}


int main(int argc, char const *argv[])
{
	int numD;
	cout<<"NUMBER OF COINS : ";
	cin>>numD;
	int * d = new int[numD];
	cout<<"COINS : ";
	for(int i = 0 ; i<numD ; i++) cin>>d[i];
	// allocate 2d array here , n+1, numD+1
	// put all -1

	int n;
	cout<<"AMOUNT : ";
	cin>>n;	

	int ** output = new int*[n+1];
	for(int i = 0 ; i<=n ; i++){
		output[i] = new int[numD+1];
		memset(output[i],-1,(numD+1)*sizeof(int));
	}
	cout<<CoinChange2(n,d,numD,output)<<endl;
	cout<<CoinChange(n,d,numD)<<endl;
	return 0;
}