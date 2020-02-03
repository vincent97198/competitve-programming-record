#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

vector<int> G[N];
int n,pre[N];

struct node{
	int depth,index;
};

void init()
{
	cin >> n;
	int a,b;
	for(int i=0;i<n-1;++i){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
}

node dfs(int now,int d,int p)
{
	node MAX=node{d,now},tmp;
	for(int i=0;i<G[now].size();++i){
		if(G[now][i]==p)
			continue;
		tmp=dfs(G[now][i],d+1,now);
		if(tmp.depth>MAX.depth){
			pre[now]=G[now][i];
			MAX.depth=tmp.depth;
			MAX.index=tmp.index;
		}
	}
	return MAX;
}

node bfs(node A,node B)
{
	queue<int> q;
	int dis[N];
	bool visit[N];
	memset(visit,0,sizeof(visit));
	for(int i=A.index;i!=B.index;i=pre[i]){
		q.push(i);
		visit[i]=true;
		dis[i]=0;
	}
	q.push(B.index);	visit[B.index]=true;	dis[B.index]=0;

	node MAX=node{0,pre[A.index]};
	int cur;
	while(!q.empty()){
		cur=q.front();	q.pop();
		for(int i=0;i<G[cur].size();++i){
			int next=G[cur][i];
			if(!visit[next]){
				visit[next]=true;
				dis[next]=dis[cur]+1;
				q.push(next);
				if(MAX.depth<dis[next]){
					MAX.depth=dis[next];
					MAX.index=next;
				}
			}
		}
	}

	return MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	init();

	node A=dfs(1,0,0);
	node B=dfs(A.index,0,0);

	node C=bfs(A,B);	//distance from diameter to vertices

	cout << B.depth+C.depth << endl;
	cout << A.index << " " << B.index << " " << C.index << endl;

	return 0;
}
