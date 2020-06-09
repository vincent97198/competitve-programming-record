#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

struct node{
	ll cost,initBit,goalBit;
};

int n;
ll ans=0;
node arr[N];
vector<int> G[N];

pair<int,int> dfs(int now,int par)
{
	pair<int,int> nowNode=make_pair( (arr[now].initBit==0 && arr[now].goalBit==1) , (arr[now].initBit==1 && arr[now].goalBit==0) );
	for(int next:G[now]){
	    if(next==par)   continue;
		arr[next].cost=min(arr[next].cost,arr[now].cost);
		pair<int,int> tmp=dfs(next,now);
		nowNode.first+=tmp.first;
		nowNode.second+=tmp.second;
	}
	ll MIN0=min(nowNode.first,nowNode.second);
	ans+=MIN0*2*arr[now].cost;
	nowNode.first-=MIN0,nowNode.second-=MIN0;
	return nowNode;
}

void init()
{
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i].cost >> arr[i].initBit >> arr[i].goalBit;
	for(int i=1;i<n;++i){
		int u,v;	cin >> u >> v;
		G[u].push_back(v);	G[v].push_back(u);
	}
}

void solve()
{
    if(dfs(1,-1)!=make_pair(0,0))
        cout << -1;
    else
        cout << ans;
    cout << endl;
}

int main()
{
	init();
	solve();

	return 0;
}

