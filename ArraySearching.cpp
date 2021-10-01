#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

////////////////////Iterative Method O(logN)/////////////////////////////////////
int binarySearchI(int *arr, int n, int key) {
	int low = 0, high = n - 1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] == key) {
			return mid;
		}
		else if(arr[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
} 

/////////////////////////RecursiveMethod///////////////////////////////////////////////////
int binarySearchR(int *arr, int low, int high, int key) {
	int mid = (low + high) / 2;
	if(low > high)
	return -1;
	if(arr[mid] == key) {
		return mid;
	}
	if(arr[mid] < key)
     	binarySearchR(arr, mid + 1, high, key);
	else 
	    binarySearchR(arr, low, mid - 1, key);
	
} 

////////////////////////////INdexOfFirstOccurrence O(logN)/////////////////////////////
int indexOfFirstOccurence(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] > x) {
			high = mid - 1;
		} 
		else if(arr[mid] < x) {
			low = mid + 1;
		}
		else {
			if(mid == 0 || arr[mid-1] != arr[mid]) {
				return mid;
			}
			else {
				high = mid - 1;
			}
		}
		
	}
	return -1;
}

///////////////////////////IndexOfLastOccurenceO(logN)/////////////////////////////
int indexOfLastOccurence(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] > x) {
			high = mid - 1;
		} 
		else if(arr[mid] < x) {
			low = mid + 1;
		}
		else {
			if(mid == n - 1 || arr[mid] != arr[mid + 1]) {
				return mid;
			}
			else {
				low = mid + 1;
			}
		}
		
	}
	return -1;
}

/////////////////CountOccurrenceO(logN)////////////////////////////////////////
int countOccurrence(int arr[], int n, int x) {
	int first = indexOfFirstOccurence(arr, 6, x);
	if(first == -1)
	return 0;
	return (indexOfLastOccurence(arr, 6, x) - first + 1);
}

///////////////////Count1'sOccurrenceO(logN)////////////////////////////////////
int count1SOccurence(int arr[], int n) {
	int low = 0, high = n - 1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] == 0) {
			low = mid + 1;
		} 
		else {
			if(mid == 0 || arr[mid-1] != arr[mid]) {
				return (n - mid);
			}
			else {
				high = mid - 1;
			}
		}
		
	}
	return 0;
}

//////////////////////////////////SquareRootO(sqrt(n))//////////////////////////////////
int sqRootFloor(int n) {
	int i = 1;
	while(i * i <= n) {
		i++;
	}
	return i - 1;
}

/////////////////////////////SquareRootO(logN)/////////////////////////////////////////
int sqRootFloor1(int n) {
	int low = 1, high = n, ans = -1;
	while(low <= high) {
		int mid = (low + high) / 2;
		int temp = mid * mid;
		if(temp == n) {
			return mid;
		}
		else if(temp > n) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
			ans = mid;	
		}
	}
	return ans;
}

////////////////////////////////////////////SearchinInfiniteArrayO(position)///////////////////
int infiniteSearch(int arr[], int x) {
	int i = 0;
	while(true) {
		if(arr[i] == x) {
			return i;
		}
		if(arr[i] > x) {
			return -1;
		}
		i++;
	}
}
int main() {
	int arr[] = {0,1,1,1,1};
	//cout<<binarySearchR(arr, 0, 5, 70)<<endl;
	//cout<<indexOfLastOccurence(arr, 6, 10)<<endl;
	//cout<<countOccurrence(arr, 6, 1)<<endl;
	//cout<<count1SOccurence(arr, 5)<<endl;
	//cout<<sqRootFloor1(10)<<endl;
	cout<<infiniteSearch(arr, 1)<<endl;
	return 0;
}
