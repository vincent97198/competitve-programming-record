#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

ll n,g,b,half;

bool check(ll now)
{
	ll G=now/(g+b)*g+min(g,now%(g+b));

	if(now>=n && G>=(n+1)/2)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> g >> b;
	
		ll l=0,r=1e18+7;
		while(r-l>1){
			ll mid=(l+r)/2;
			
			if(check(mid))
				r=mid;
			else
				l=mid;
		}
		
		if(check(l))
			cout << l << endl;
		else
			cout << r << endl;
	}
	return 0;
}
