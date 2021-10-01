#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void iskthBitSet(int n, int k) {
	if(((n >> (k-1)) & 1) != 0){
		cout<<"Yes"<<endl;
	}
	else
	cout<<"No"<<endl;
}
bool powerOfTwo(int n) {
	if(n == 0)
	return false;
	if((n & (n - 1) ) == 0)
	return true;
	else return false;
}
void powerSet(string str[]) {
	int r = str.size();
	int powsize = pow(2, r);
	for(int count = 0; count < powsize; count++) {
		for(int j = 0; j < r; j++) {
			if((count & (1 << j)) != 0) {
				cout<<str[j];
			}
		}
		cout<<endl;
	}
}
int main() {
	string str;
	cin>>str;
	//iskthBitSet(5, 3);
	powerSet(&str);
	return 0;	
}
