#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N=100050;

int n,a,b,da,db,d[N],MAX=0,p;
vector<int> G[N];

void dfs(int now,int pre)
{
	if(d[now]>MAX){
		MAX=d[now];
		p=now;
	}
	for(int next:G[now]){
		if(pre==next)	continue;
		d[next]=d[now]+1;
		dfs(next,now);
	}
}

void init()
{
	cin >> n >> a >> b >> da >> db;
	MAX=0;
	for(int i=0;i<=n;++i)	G[i].clear();
	for(int i=1;i<=n-1;++i){
		int u,v;	cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

bool solve()
{
	d[a]=0;
	dfs(a,-1);
	if(d[b]<=da)	return true;
	else{
		MAX=0;
		d[p]=0;
		dfs(p,-1);
		if(d[p]<=2*da)	return true;
		else if(2*da<db)	return false;
		else	return true;
	}
}

signed main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;	cin >> t;
	while(t--){
		init();
		if(solve())

