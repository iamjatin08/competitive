#include<iostream>
using namespace std;

class Triplet{
public:
	int gcd;
	int x;
	int y;
};

Triplet gcdExtendedEuclid(int a, int b){
	if(b == 0){
		Triplet myAns;
		myAns.gcd = a;
		myAns.x = 1;
		myAns.y = 0;
		return myAns;
	}
	// if(b>a) return gcdExtendedEuclid(b,a);

	Triplet smallAns =  gcdExtendedEuclid(b,a%b);
	// extended euclid says;
	Triplet myAns;
	myAns.gcd = smallAns.gcd;
	myAns.x = smallAns.y;
	myAns.y = smallAns.x - ((a/b)*(smallAns.y));
	return myAns;
}

int modInverse(int A , int M){
	Triplet  ans = gcdExtendedEuclid(A,M);
	cout<<"MULTIPLICATIVE MODULE INVERSE IS "<<ans.x<<endl;
}




int main(int argc, char const *argv[])
{
	int a,b;
	cout<<"ENTER NUMBERS: ";
	cin>>a>>b;

	modInverse(a,b);	
	// cout<<"GCD IS : ";
	// Triplet ans = gcdExtendedEuclid(a,b);
	// cout<<ans.gcd<<endl;
	// cout<<"x is "<<ans.x<<endl;
	// cout<<"y is "<<ans.y<<endl;

	return 0;
}