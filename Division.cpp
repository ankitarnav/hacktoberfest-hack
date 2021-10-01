#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void Solve() {
	ll pi,qi;
	cin>>pi>>qi;
	int res=2;
	int temp1 = max(pi, qi);
	for(int i=2; i<=temp1; i++) {
		if(pi % qi != 0) {
			cout<<pi<<endl;
			return;
		}
		if(pi % i ==0 && i % qi !=0) {
			res = res < i ? i : res;
		}
	}
	cout<<res<<endl;	
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		Solve();
	}
	return 0;
}
