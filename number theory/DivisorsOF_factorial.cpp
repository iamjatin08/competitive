#include<bits/stdc++.h>
using namespace std;

#define MAX 50001
#define pb push_back
#define MOD 1000000007

typedef long long ll;


vector<int>* sieve(){
	bool isPrime[MAX];
	vector<int>* primes = new vector<int>();
	for(int i = 2; i<=MAX;i++) isPrime[i] = true;
	for(int i = 0 ; i*i <= MAX ; i++){
		if(isPrime[i]){
			for(int j = i*i ; j<=MAX ;  j+=i){
				isPrime[j] = false;
			}
		}
	}
	primes->pb(2);
	for(int i = 3; i<=MAX ; i++){
		if(isPrime[i]){
			primes->pb(i);
		}
	}
	return primes;
}

ll divisors(int n, vector<int>* &primes){
	ll result = 1;
	for(int i = 0 ; primes->at(i)<= n ; i++){	
		int k = primes->at(i);
		ll count = 0;
		while((n/k)!=0){
			count = (count+(n/k))%MOD;
			k = k*primes->at(i);
		}	
		result = (result * ((count+1)%MOD))%MOD;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<int>* primes = sieve();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<divisors(n,primes)<<endl;
	}

	return 0;
}