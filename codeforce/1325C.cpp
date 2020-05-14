#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct edge{
	int to,from;
	int id=-1;
};

int degree[N];

int main()
{
	int n;
	vector<edge> E;
	cin >> n;
	for(int i=1;i<n;++i){
		edge EDGE;
		cin >> EDGE.to >> EDGE.from;
		E.push_back(EDGE);
		++degree[EDGE.to],++degree[EDGE.from];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(degree[i]>=3){
			for(int j=0;j<E.size();++j){
				if(E[j].to==i || E[j].from==i)
					E[j].id=cnt++;
			}
			break;
		}
	}
	for(int i=0;i<E.size();++i)
		if(E[i].id==-1)
			cout << cnt++ << endl;
		else
			cout << E[i].id << endl;
	return 0;
}
