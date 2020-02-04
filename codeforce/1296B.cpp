#include <bits/stdc++.h>
#define ll long long
#define N 100000
 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
 
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll ans=0,tmp;
		while(n>=10){
			tmp=n/10;
			ans+=(tmp*10);
			n=(n%10)+tmp;
		}
		ans+=n;
		cout << ans << endl;
	}
 
	return 0;
}
