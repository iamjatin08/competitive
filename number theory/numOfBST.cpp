#include<iostream>
#include<math.h>
using namespace std;

int balanceBST(int h){
	if(h==0 or h == 1) return 1;

	int m = pow(10,9)+7;

	int x = balanceBST(h-1);
	int y = balanceBST(h-2);

	long res1 = ((long)x)*x;
	long res2 = ((long)x)*y*2;

	int ans1 = (int)(res1%m);
	int  ans2 = (int)(res2%m);
	int ans = ((ans1+ans2)%m);
	return ans ;
}



int main(int argc, char const *argv[])
{
	int h;
	cout<<"ENTER HEIGHT: ";
	cin >> h; 
	cout<<"NUMBER OF BALANCED BST ARE "<<balanceBST(h)<<endl;

	return 0;
}