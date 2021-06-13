#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

bool checkPRIME(int n){
	int count = 0;
	for(int i = 1 ; i*i<=n ; i++){
		if(n%i == 0){
			if(i*i == n) count++;
			else count+=2;
		}
	}
	if(count == 2) return true;
	return false;
}

void makesieve(int n){
	bool isPrime[n+1];
	for(int i = 0 ; i<=n ; i++) isPrime[i] = true;
	isPrime[0] = false;
	isPrime[1] = false;
	int count = 0;
	for(int i = 0 ; i*i<=n ; i++){
		if(isPrime[i]){
			for(int j = i*i ; j<=n ; j+=i){
				isPrime[j] = false;
			}
		}
	}
	for(int i = 0 ; i<=n ; i++){
			if(isPrime[i]) 
				count++;
			}

	cout<<"NUMBER OF PRIME NUMBERS LESS THAN "<<n<<" : "
			<<count<<endl;
}




int main(int argc, char const *argv[])
{
	int n ;
	cout<<"ENTER NUMBER: ";
	cin>>n;
	makesieve(n);
	// cout<<endl;
	// cout<<"NUMBER OF PRIME NUMBERS LESS THAN "<<n<<"->"
	// 		<<count<<endl;
	
	
	return 0;
}