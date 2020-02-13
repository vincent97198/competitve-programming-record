#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

struct edge{
  int to,dis;
  edge()=default;
  bool operator< (const edge &a)const{
      return dis>a.dis;
  }
};

vector<edge> G[N];
int ans[N],p[N],q[N],r[N];;

void solve()
{
    memset(ans,0x7f,sizeof(ans));
    priority_queue<edge> pq;

    pq.push(edge{1,0});
    ans[1]=0;

    edge now;
    while(!pq.empty()){
        now=pq.top();	pq.pop();
        if(ans[now.to]<now.dis)
            continue;
        for(int i=0;i<G[now.to].size();++i){
            if(ans[G[now.to][i].to]>G[now.to][i].dis+ans[now.to]){
                ans[G[now.to][i].to]=G[now.to][i].dis+ans[now.to];
                pq.push(edge{G[now.to][i].to,ans[G[now.to][i].to]});
            }
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int m,n;
    cin >> m >> n;
    for(int i=0;i<n;++i){
        cin >> p[i] >> q[i] >> r[i];
        G[p[i]].push_back(edge{q[i],r[i]});
    }
    solve();
    ll sum=0;
    for(int i=1;i<=m;++i){
        if(ans[i]<=1e9+7)
            sum+=ans[i];
        else{
            cout << 0 << endl;
            return 0;
        }
    }

    for(int i=0;i<=m;++i)
        G[i].clear();
    for(int i=0;i<n;++i){
        G[q[i]].push_back(edge{p[i],r[i]});
    }

    solve();
    for(int i=1;i<=m;++i){
        if(ans[i]<=1e9+7)
            sum+=ans[i];
        else{
            cout << 0 << endl;
            return 0;
        }
    }

    cout << sum << endl;

    return 0;
}

