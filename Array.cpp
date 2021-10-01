#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void secondLargest(int *arr, int n) {
	int res = -1, largest = 0;
	for(int i = 1; i < n; i++) {
		if(arr[i] > arr[largest]) {
			res = largest;
			largest = i;
		}
		else if(arr[i] != arr[largest]) {
			if(res == -1 || arr[i] > arr[res])
			    res = i;
		}
	}
	cout<<res<<endl;	
}
//////////////////////////////////////////////////////////////////////////////////

int  removeDuplicate(int *arr, int n) {
	int temp = -1, j = 0;
	sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		if(arr[i] != temp) {
			arr[j++] = arr[i];
			temp = arr[i];
		}
	}
	return j;
}
////////////////////////////////////////////////////////////////////////////////

void moveZerotoEnd(int *arr, int n) {
	int count = 0, i = 0, j = 0;
	while(i < n) {
		if(arr[i] == 0) {
			count++;
		}
		else {
			arr[j++] = arr[i];	
		}
		i++;
	}
	for(; count > 0; count--) {
		arr[j++] = 0;	 
	}	
}
///////////////////////////////////////////////////////////////////////////////

void moveZerotoEnd1(int *arr, int n) {
	int count = 0, i = 0;
	while(i < n) {
		if(arr[i] == 0) {
			swap(arr[i], arr[n-1]);
			n--;
		}
		else {
			i++;	
		}
	}	
}
//////////////////////////////////////////////////////////////////////////////////
void leftRotate(int *arr, int n) {
	int x = arr[0];
	for(int i = 1; i < n; i++) {
		arr[i-1] = arr[i];	
	}
	arr[n-1] = x;
}
/////////////////////////////o(nd)//////////////////////////////////////////////////////

void leftRotateD(int *arr, int n, int d) {
	for(int i = 1; i <= d; i++) {
	    int x = arr[0];
	    for(int i = 1; i < n; i++) {
		    arr[i-1] = arr[i];	
     	}
	    arr[n-1] = x;
	}
}
///////////////////////////o(n)/////////////////////////////////////////////////////////

void leftRotateD1(int *arr, int n, int d) {
	int temp[d];
	for(int i = 0; i < d; i++) {
		temp[i] = arr[i];
	}
	for(int i = d; i < n; i++) {
		arr[i-d] = arr[i];
	}
	for(int i = 0; i < d; i++) {
		arr[n-d+i] = temp[i];	
    }
}
////////////////////////////////////////////////////////////////////////////////////

void reverse(int *arr, int low, int high) {
	while(low < high) {
		swap(arr[low], arr[high]);
		low++;
		high--;
	}
}
//////////////////////////////////////////////////////////////////////////////////////

void leftRotateD2(int *arr, int n, int d) {
	reverse(arr, 0, d-1);
	reverse(arr, d, n-1);
	reverse(arr, 0, n-1);
}
////////////////////////////////////////////////////////////////////////////////////
void leadersElement(int *arr, int n) {
	int temp = arr[n-1];
	cout<<temp<<" ";
	for(int i = n-2; i >= 0; i--) {
		if(arr[i] > temp) {
			cout<<arr[i]<<" ";
			temp = arr[i];
		}	
	}
}
/////////////////////o(n2)////////////////////////////////////////////////////

void maxDifference(int *arr, int n) {
	int res = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			int temp = arr[j] - arr[i];
			res = max(res, temp);
		}
	}
	cout<<res<<endl;
}
//////////////////////////////////////////////////////////////////////////////

void maxDifference1(int *arr, int n) {
	int res = arr[1] -arr[0];
	int minval = arr[0];
	for(int i = 1; i < n; i++) {
		res = max(res, arr[i]-minval);
		minval = min(minval, arr[i]);
		
	}
	cout<<res<<endl;
}
/////////////////////////////o(n2)///////////////////////////////////////////////

void trapRainWater(int *arr, int n) {
	int res = 0;
	for(int i = 1; i < n-1; i++) {
		int lmax = arr[i];
		for(int j = 0; j < i; j++) {
			lmax = max(lmax, arr[j]);
		}
		int rmax = arr[i];
		for(int j = i+1; j < n; j++) {
			rmax = max(rmax, arr[j]);
		}
		res += min(lmax, rmax) - arr[i];
	}
	cout<<res<<endl;
}
///////////////////////////////o(n)//////////////////////////////////////////

void trapRainWater1(int *arr, int n) {
	int res = 0;
	int lmax[n];
	int rmax[n];
	lmax[0] = arr[0];
	rmax[n-1] = arr[n-1];
	
	for(int i = 1; i < n; i++) {
		lmax[i] = max(arr[i], lmax[i-1]);
	}
	
	for(int i = n-2; i >= 0; i--) {
		rmax[i] = max(arr[i], rmax[i+1]);
	}
	
	for(int i = 1; i < n-1; i++) {
		res = res + min(lmax[i], rmax[i]) - arr[i];
	}
	
	cout<<res<<endl;
}
////////////////////////////////////////O(n2)//////////////////////////////////

void maxSubArray(int *arr, int n) {
	int res = arr[0];
	for(int i = 0; i < n-1; i++) {
		int curr = 0;
		for(int j = i; j < n; j++) {
			curr += arr[j];
			res = max(res, curr);	
		}
	}
	cout<<res<<endl;
}
////////////////////////////O(n)///////////////////////////////////////////////

void maxSubArray1(int *arr, int n) {
	int res = arr[0];
	int maxEnding = arr[0];
	for(int i = 1; i < n; i++) {
		maxEnding = max(arr[i] + maxEnding, arr[i]);
		res = max(res, maxEnding);
	}
	cout<<res<<endl;
}
/////////////////////////////O(n*k)////////////////////////////////////

void maxSumOfK(int *arr, int n, int k) {
	int i = 0;
	int res = 0;
	while(i + k - 1 < n) {
		int j = 0;
		int sum = 0;
		while(j < k) {
			sum += arr[i+j];
			j++;
		}
		res = max(res, sum);
		i++;
	}
	cout<<res;
}
////////////////////////////////////////////o(n)/////////////////////

void maxSumOfK1(int *arr, int n, int k) {
	int curr_sum = 0;
	for(int i = 0; i < k; i++) {
		curr_sum += arr[i];
	}
	int res = curr_sum;
	for(int i = k; i < n; i++) {
		curr_sum += arr[i] - arr[i-k];
		res = max(res, curr_sum);
	}
	cout<<res<<endl;
}
////////////////////////////////////////////O(n)//////////////////////////////////////

bool subarrayGivenSum(int *arr, int n, int sum) {
	
	
	///KROOOOOO//////////
	
	
	
	
	
	
}
/////////////////////////////O(n)///////////////////////////////////////////////////

int getSum(int *arr, int n, int l, int r) {
	int prefix_sum[n];
	prefix_sum[0] = arr[0];
	for(int i = 1; i < n; i++) {
		prefix_sum[i] = prefix_sum[i-1] + arr[i];
	}
	
	if(l) {
		return prefix_sum[r] - prefix_sum[l-1];
	}
	else 
	return prefix_sum[r];
}
//////////////////////////////////////////////O(n)///////////////////////////////////////////

bool equilibriumPoint(int *arr, int n) {
	int total_sum = 0, l_sum = 0, r_sum = 0;
	for(int i = 0; i < n; i++) {
		total_sum += arr[i];
	}
	for(int i = 0; i < n; i++) {
		r_sum = total_sum - arr[i];
		if(l_sum == r_sum) {
			return true;
		}
		l_sum += arr[i];
		total_sum -= arr[i];
	}
	return false;
}
int main() {
	int arr[] = {2,-6,4,7};
	//secondLargest(arr, 5);
	//int l = removeDuplicate(arr, 7);
	//moveZerotoEnd1(arr, 7);
	//leftRotateD2(arr, 7, 3);
	//for(int i = 0; i < 7; i++) {
	//	cout<<arr[i]<<" ";
	//}
	//leadersElement(arr, 7);
	//maxDifference(arr, 7);
	//trapRainWater1(arr, 7);
	//maxSubArray(arr, 7);
	//maxSumOfK1(arr, 5, 3);
	//cout<<subarrayGivenSum(arr, 5, 8)<<endl;
	//cout<<getSum(arr, 7, 0, 2);
	cout<<equilibriumPoint(arr, 4);
	return 0;
}
