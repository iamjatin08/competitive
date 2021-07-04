#include<bits/stdc++.h>
using namespace std;


int kadane(int *arr , int n){
	int currentSum = 0 ;
	int bestSum = 0;
	for(int i = 0 ; i<n ; i++){
		currentSum += arr[i];
		if(bestSum<currentSum){
			bestSum = currentSum;
		}
		if(currentSum<0){
			currentSum = 0;
		}
	}
	return bestSum;
}




int main(int argc, char const *argv[])
{
	int size;
	cout<<"SIZE : ";
	cin>>size;
	int* arr = new int[size];
	cout<<"Enter values : ";
	for(int i = 0 ; i<size ; i++){
		cin>>arr[i];
	}
	int ans  = kadane(arr,size);
	cout<<"ANS : "<<ans<<endl;
	delete []  arr;
	return 0;
}