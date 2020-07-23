#include <bits/stdc++.h>
#define N 200005
#define ll long long

using namespace std;

int t,n,m,vis[N];
vector<int> G[N],order;
vector<pair<int,int>> E;

void dfs(int now)
{
    vis[now]=t;
    for(int next:G[now]){
        if(vis[next]!=t)  dfs(next);
    }
    order.push_back(now);
}

void init()
{
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int type,a,b;   cin >> type >> a >> b;
        if(type==1)
            G[a].push_back(b);
        else
            E.push_back({a,b});
    }
}

void solve()
{
    for(int i=1;i<=n;++i){
        if(vis[i]!=t)
            dfs(i);
    }

    int pos[N];
    reverse(order.begin(),order.end());
    for(int i=0;i<n;++i)    pos[order[i]]=i;

    bool acyclic=true;
    for(int i=1;i<=n;++i){
        for(int to:G[i])
            if(pos[i]>pos[to])  acyclic=false;
    }

    if(acyclic){
        cout << "YES\n";
        for(int i=1;i<=n;++i){
            for(int j:G[i])
                cout << i << " " << j << endl;
        }
        for(pair<int,int> edge:E){
            if(pos[edge.first]<pos[edge.second])
                cout << edge.first << " " << edge.second << endl;
            else
                cout << edge.second << " " << edge.first << endl;
        }
    }
    else
        cout << "NO\n";
}

void clear()
{
    for(int i=1;i<=n;++i)    G[i].clear();
    E.clear();
}

int main()
{
    cin >> t;   memset(vis,-1,sizeof(vis));
    while(t--){
        init();
        solve();
        clear();
    }

    return 0;
}

/*
 *
 */
