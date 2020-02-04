#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

ll gen(ll x,ll y)
{
	return x*(ll)200005+y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n;
		string s;
		map<ll,ll> MAP;
		MAP[0]=0;
		cin >> n >> s;
		
		ll l,r,MIN=N*10,nowx=0,nowy=0;
		for(ll i=0;i<s.size();++i){
			if(s[i]=='L')
				--nowx;
			else if(s[i]=='R')
				++nowx;
			else if(s[i]=='U')
				++nowy;
			else if(s[i]=='D')
				--nowy;

			ll tmp=gen(nowx,nowy);
			if(MAP.find(tmp)!=MAP.end()){
				ll pos=MAP[tmp],len=i+1-MAP[tmp];
				if(len<MIN){
					MIN=len;
					r=i+1;	l=MAP[tmp]+1;
				}
			}

			MAP[tmp]=i+1;
		}
		if(MIN!=N*10)
			cout << l << " " << r << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}
