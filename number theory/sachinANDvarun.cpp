#include <iostream>
#include <algorithm>
using namespace std;

class Triplet{
public:
	long long gcd;
	long long x;
	long long y;
};

Triplet gcdExtendedEuclid(long long a, long long b){
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

long long modInverse(long long A , long long M){
	long long  x = gcdExtendedEuclid(A,M).x;
	return (x%M + M )%M;
} 



int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--){
		long long a,b,d;
		cin>>a>>b>>d;

		long long g = __gcd(a,b);
		a/=g;
		b/=g;
		d/=g;

		if(d%g){
			cout<<0<<endl;
			continue;
		}
		if(d == 0){
			cout<<1<<endl;
			continue;
		}
		

		long long y1 = ((d%a)*modInverse(b,a)%a);
		long long firstValue = (d/b);
		if(d<(y1*b)){
			cout<<0<<endl;
			continue;
		}
		long long n = (firstValue - y1)/a;
		long long ans = n+1;
		cout<<ans<<endl;
	}
	return 0;
}