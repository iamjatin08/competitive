#include <bits/stdc++.h>
using namespace std;

long long merge(int arr[] , int start ,int mid, int end){
	
	int i = start , j = mid, k = 0;
	int temp[end-start+1];
	long long count = 0;
	while(i<mid  and j<=end){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			count += mid-i;
		}
	}
	while(i<mid) temp[k++] = arr[i++];
	while(j<=end) temp[k++] = arr[j++];
	for(i = start ,k=0 ; i<=end ; i++,k++){
		arr[i] = temp[k];

	}
	return count;

}

long long mergeSort(int arr[], int start, int end){
	
		long long count = 0;
		if(end>start){
	
		int mid = (start + end)/2;

		long long leftAns = mergeSort(arr,start,mid);
		long long rightAns = mergeSort(arr,mid+1,end);
		long long ans = merge(arr,start,mid+1,end);
		return ans + leftAns + rightAns;
	}
	return count;
	

}



long long solve(int A[] , int n){
	long long ans = mergeSort(A,0,n-1);
	return ans;
}



int main(int argc, char const *argv[])
{
	int arr[] = {5,4,2,3,1};
	cout<<solve(arr,5)<<endl;
	return 0;
}