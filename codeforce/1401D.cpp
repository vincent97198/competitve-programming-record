#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N=100005;
const ll MOD=1000000007;

vector<ll> G[N],edge,p;
ll n,m,child[N],ans=0;

void dfs(int now,int pre)
{
    child[now]=1;
    for(int next:G[now]){
        if(next==pre)   continue;
        dfs(next,now);
        child[now]+=child[next];
    }
    if(now!=1)
        edge.push_back(child[now]*(n-child[now]));
}

int main()
{
    int t;  cin >> t;
    while(t--){
        cin >> n;
        //init start
        ans=0;
        p.clear();edge.clear();
        for(int i=0;i<=n;++i)
            G[i].clear();
        //init end
        for(int i=0;i<n-1;++i){
            int u,v;    cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);

