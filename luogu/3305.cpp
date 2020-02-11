#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 105

using namespace std;

struct edge{
	int from,to;
	double MAXflow,nowflow;
};

int n,m,p,START=1,END=N,level[N],cur[N];
double ansflow;
vector<int> G[N];
vector<edge> E,E_SAVE;
const double eps=1e-8;

void add_edge(int FROM,int TO,double MAXFLOW)
{
	G[FROM].push_back(E.size());
	E.push_back(edge{FROM,TO,MAXFLOW,0});
}

void clean_edge()
{
	for(int i=0;i<N;++i)
		G[i].clear();
	E.clear();
}

void build_edge(double flow)
{
	for(int i=0;i<m;++i){
		add_edge(E_SAVE[i].from,E_SAVE[i].to,min(flow,E_SAVE[i].MAXflow));
		add_edge(E_SAVE[i].to,E_SAVE[i].from,0);
	}
}

bool bfs()
{
	memset(level,0xff,sizeof(level));
    level[START]=0;

	queue<int> q;
	q.push(START);

	int now;
	edge NOW;
	while(!q.empty()){
		now=q.front();	q.pop();

		for(int i=0;i<G[now].size();++i){
			NOW=E[G[now][i]];
			if(level[NOW.to]==-1 && (NOW.MAXflow-NOW.nowflow)>eps){
				level[NOW.to]=level[now]+1;
				q.push(NOW.to);

				if(NOW.to==END)
					return true;
			}
		}
	}

	return false;
}

double dfs(int now,double minflow)
{
	if(now==END)
		return minflow;

	edge NOW;
	double flow=0;
	for(int &i=cur[now];i<G[now].size();++i){
		NOW=E[G[now][i]];

		if((NOW.MAXflow-NOW.nowflow)>eps && level[NOW.to]==level[now]+1){
			double tmp=dfs(NOW.to,min(minflow,NOW.MAXflow-NOW.nowflow));
			flow+=tmp;
			minflow-=tmp;
			E[G[now][i]].nowflow+=tmp;
			E[G[now][i]^1].nowflow-=tmp;

			if(minflow<eps)
				break;
		}
	}
	return flow;
}

double dinic()
{
	double flow_sum=0,flow;
	while(bfs()){
		memset(cur,0,sizeof(cur));
		while(true){
			flow=dfs(START,1e9);
			if(flow<eps)
			    break;
			flow_sum+=flow;
		}
	}
	return flow_sum;
}

bool check(double flow)
{
	clean_edge();
	build_edge(flow);

    return fabs( ansflow - dinic() ) < eps;
}

void create_ansflow()
{
	build_edge(1e9);
	ansflow=dinic();
}

void init()
{
	cin >> n >> m >> p;

	int FROM,TO;
    double MAXFLOW;
	for(int i=0;i<m;++i){
		cin >> FROM >> TO >> MAXFLOW;
		E_SAVE.push_back(edge{FROM,TO,MAXFLOW,0});
	}

	END=n;
}

void solve()
{
	double l=0,r=1e9,mid;

	create_ansflow();

	while(r-l>1e-5){
		mid=(l+r)/2;

		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	cout << (int)(ansflow+0.1) << endl;
	cout << fixed << setprecision(4) << r*p << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	init();
	solve();

	return 0;
}

