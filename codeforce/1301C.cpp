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
		ll n,m;
		cin >> n >> m;
		ll tmp=n-m;
		ll tmp2=tmp/(m+1);
		ll tmp3=tmp%(m+1);

		ll ans=(n*n+n)/2;
		ll tmp33=((tmp2+1)*(tmp2+1)+tmp2+1)/2;
		tmp2=(tmp2*tmp2+tmp2)/2;

		cout << ans-tmp2*(m+1-tmp3)-tmp33*tmp3 << endl;
	}

	return 0;
}
