#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n" 
int maxSum(int *arr, int n) {
	int res = arr[0];
	for(int i= 0; i < n; i++) {
		int curr = 0;
		for(int j= i; j < n; j++) {
			curr += arr[j];
			res = max(curr, res);
		}
	}
	return res;
}
int maxEvenOdd(int *arr, int n) {
	int temp = 1, count = 1;
	for(int j = 0; j < n-1; j++) {
			if(arr[j] % 2 == 0 && arr[j+1] % 2 != 0) {
				count++;
			}
			else if(arr[j] % 2 != 0 && arr[j+1] % 2 == 0) {
				count++;
			}
			else {
			    count = 1;
			}
		}
	return max(temp,count);
}
int main() {
	int arr[4] = {7,10,13,14};
	cout<<maxEvenOdd(arr, 4);
	return 0;
}
