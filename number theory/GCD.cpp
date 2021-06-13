#include<iostream>
using namespace std;

int GCD_basic(int a, int b){
	int ans = 1;
	int n = min(a,b);
	for(int i = 2; i<=n ; i++){
		if(a%i==0 and b%i==0){
			ans = max(ans,i);
		}
	}
	return ans;
}

// EUCLID ALGORITHM
int GCD(int a, int b){
	if(a==0 or b==0 ){
		if(a==0) return b;
		else return a;
	}
	
	if(a>b) return GCD(a%b,b);
	else return GCD(a,b%a);
}



int main(int argc, char const *argv[])
{
	int a, b;
	cout<<"ENTER NUMBERS: ";
	cin>>a>>b;
	cout<<"GCD IS ";
	cout<<GCD(a,b)<<endl;
	cout<<"GCD IS ";
	cout<<GCD_basic(a,b)<<endl;


	return 0;
}