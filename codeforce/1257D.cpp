#include <bits/stdc++.h>
#define N 200005

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,a[N],m,power[N];
		cin >> n;
		memset(power,0,sizeof(int)*(n+5));
		for(int i=0;i<n;++i)
			cin >> a[i];
		cin >> m;
		for(int i=0;i<m;++i){
			int tmpa,tmpb;	cin >> tmpa >> tmpb;
			power[tmpb]=max(tmpa,power[tmpb]);
		}
		for(int i=n+3;i>=0;--i)
			power[i]=max(power[i],power[i+1]);

		int ans=0,pos=0;	bool flag=false;
		while(pos<n){
			int now=pos,tmp=a[pos];
			while(now<n){
				tmp=max(tmp,a[now]);
				if(tmp>power[now-pos+1])
					break;
				++now;
			}
			++ans;
			if(now==pos){
				flag=true;
				break;
			}
			if(now==n)
				break;
			pos=now;
		}
		if(flag)
			cout << -1;
		else
			cout << ans;
		cout << endl;
	}
	return 0;
}

