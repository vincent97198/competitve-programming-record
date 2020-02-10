#include <bits/stdc++.h>
#define int long long
#define ll long long
#define N 1005

using namespace std;

struct edge{
	int from,to,c;
};

struct pos{
	int x,y;
};

int n,boss[N],group[N];
vector<edge> G;
vector<pos> v;

void init()
{
	G.clear();
	v.clear();

	cin >> n;
	int a,b;
	for(int i=0;i<n;++i){
		cin >> a >> b;
		for(int j=0;j<v.size();++j){
			if(a==v[j].x || b==v[j].y)
				G.push_back(edge{i,j,(abs(a-v[j].x)+abs(b-v[j].y))});
		}
		v.push_back(pos{a,b});
	}

	for(int i=0;i<N;++i){
		boss[i]=i;
		group[i]=1;
	}
}

bool cmp(edge a,edge b)
{
	return a.c<b.c;
}

void merge(int a,int b)
{
	if(group[a]>group[b]){
		boss[b]=a;
		group[a]+=group[b];
	}
	else{
		boss[a]=b;
		group[b]+=group[a];
	}
}

int find(int X)
{
	return (boss[X]==X)?boss[X]:find(boss[X]);
}

void solve()
{
	sort(G.begin(),G.end(),cmp);
	
	int ans=0;
	for(int i=0;i<G.size();++i){
		int FROM=find(G[i].from),TO=find(G[i].to);
		if(FROM!=TO){
			merge(FROM,TO);
			ans+=G[i].c;
		}
	}

	cout << ans << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		init();
		solve();
	}

	return 0;
}
