#include <bits/stdc++.h>
#define ll long long
#define N 300005

using namespace std;

int n,m,a[N][1<<8],num[1<<8],ans1,ans2;

bool check(int mid)
{
	for(int i=0;i<(1<<8);++i)
		num[i]=-1;
	
	for(int i=0;i<n;++i){
		int cur=0;
		for(int j=0;j<m;++j)
			if(a[i][j]>=mid)
				cur^=(1<<j);
		num[cur]=i;
	}
	if(num[(1<<m)-1]!=-1){
		ans1=num[(1<<m)-1];	ans2=num[(1<<m)-1];
		return true;
	}
	for(int i=0;i<(1<<m);++i){
		for(int j=i;j<(1<<m);++j){
			if( (i|j)==(1<<m)-1 && num[i]!=-1 && num[j]!=-1 ){
				ans1=num[i];	ans2=num[j];
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n >> m;

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin >> a[i][j];
	
	int l=0,r=1e9,mid;

	while(r-l>1){
		mid=(l+r)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	check(l);
	check(r);
	
	cout << ans1+1 << " " << ans2+1 << endl;

	return 0;
}
