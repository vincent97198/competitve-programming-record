#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define N 200005

using namespace std;

int n=0,m=0;
bool block[N];
vector<int> G[N];

bool dfs(int now,int depth)
{
    if(depth==2)
        return true;

    for(int next:G[now]){
        if(!block[next] && dfs(next,depth+1))
            return true;
    }
    return false;
}
/*
 *         1
 *       /   \
 *      2     3
 *     / \   / \
 *    4   5 6   7
 */

void init()
{
    cin >> n >> m;
    for(int i=0;i<=n;++i){
        G[i].clear();
        block[i]=false;
    }
    for(int i=0;i<m;++i){
        int a,b;    cin >> a >> b;      // a<b
        G[b].emplace_back(a);       // rev graph
    }
}

void solve()
{
    for(int i=1;i<=n;++i){
        if(!block[i] && dfs(i,0))
           block[i]=true;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        ans+=block[i];
    cout << ans << endl;
    for(int i=1;i<=n;++i)
        if(block[i])
            cout << i << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int T;  cin >> T;
    while(T--){
        init();
        solve();
    }

    return 0;
}
