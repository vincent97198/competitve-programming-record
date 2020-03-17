#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

int n,m,low[N],vis[N],cmp[N],cmpsz[N],dp[N],t=1;
vector<int> G[N],dag[N];
stack<int> stk;
bool instk[N];

void dfs(int now)
{
    vis[now]=low[now]=t++;
    stk.push(now);
    instk[now]=true;

    for(int next:G[now]){
        if(vis[next]==0)
            dfs(next);
        if(instk[next])
            low[now]=min(low[now],low[next]);
    }

    if(vis[now]==low[now]){
        int next;
        do{
            next=stk.top(); stk.pop();
            cmp[next]=now;
            instk[next]=false;
        }while(now!=next);
    }
}

void scc()
{
    for(int i=0;i<n;++i){
        if(vis[i]==0)
            dfs(i);
    }
}

int chain(int now)
{
    if(dp[now])   return dp[now];
    int ans=0;
    for(int next : dag[now])
        ans=max(ans,chain(next));

    return dp[now]=ans+cmpsz[now];
}

void init()
{
    cin >> n >> m;
    int u,v;
    for(int i=0;i<m;++i){
        cin >> u >> v;
        G[u].push_back(v);
    }
}

void solve()
{
    scc();
    for(int now=0;now<n;++now){
        int next=cmp[now];
        ++cmpsz[next];
        for(int to:G[now]){
            if(next!=cmp[to])
                dag[next].push_back(cmp[to]);
        }
    }

    int ans=0;
    for(int i=0;i<n;++i)
        ans=max(ans,chain(cmp[i]));

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}

