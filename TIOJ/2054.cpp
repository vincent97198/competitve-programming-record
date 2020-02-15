#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define N 3005

using namespace std;

struct pos{
	int x,y;
}p[N];

int n,w,l;

bool cmp(pos a,pos b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n >> l >> w;
	for(int i=0;i<n;++i)
		cin >> p[i].x >> p[i].y;

	sort(p,p+n,cmp);

	vector<int> Y;

	int L,r=0,ans=0;
	for(L=0;L<n;++L){
		while(r<n && p[r].x-p[L].x<=w){
			Y.push_back(p[r].y);
			++r;
		}
        stable_sort(Y.begin(),Y.end());
		for(int i=0;i<Y.size();++i){
			int rY=l+Y[i];
			int num=upper_bound(Y.begin(),Y.end(),rY)-Y.begin()-i;
			ans=max(ans,num);
		}
		Y.erase(lower_bound(Y.begin(),Y.end(),p[L].y));

		if(r==n)
			break;
	}
	cout << ans << '\n';

	return 0;
}

