#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	int n;	cin >> n;
	ll a[N];
	for(int i=0;i<n;++i)
		cin >> a[i];
	sort(a,a+n);
	ll k;	cin >> k;
	ll ans=0,l=0,r=1;
	while(l>=0 && r<n){
		if(k>=a[l]*a[r])
			ans=max(ans,a[l]*a[r]);
		else{
            --l;
            continue;
		}
		++r,++l;
	}
	cout << ans << endl;

	return 0;
}

