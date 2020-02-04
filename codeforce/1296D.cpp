#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

ll n,a,b,k,h;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n  >> a >> b >> k;
	ll ans=0;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i=0;i<n;++i){
		cin >> h;
		h%=(a+b);
		if(h<=a && h!=0)
			++ans;
		else if(h==0)
			pq.push( ceil(b/(double)a) );
		else
			pq.push( ceil( (h-a)/(double)a ) );
	}

	while(k>0 && !pq.empty()){
		ll tmp=pq.top();	pq.pop();
		if(tmp>k)
			break;
		else{
			k-=tmp;
			++ans;
		}
	}
	cout << ans << endl;

	return 0;
}
