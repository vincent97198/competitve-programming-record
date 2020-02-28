#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

ll n,h[N],child[N][2];
vector<int> G[N];

void init()
{
    cin >> n;
    deque<int> dq;
    for(int i=0;i<n;++i){
        cin >> h[i];
        while(!dq.empty() && h[dq.back()]<h[i]){
            int now=dq.back();
            dq.pop_back();
            if(dq.empty()){
                G[now].push_back(i);
                G[i].push_back(now);
            }
            else{
                if(h[i]>h[dq.back()]){
                    G[dq.back()].push_back(now);
                    G[now].push_back(dq.back());
                }
                else{
                    G[i].push_back(now);
                    G[now].push_back(i);
                }
            }
        }
        dq.push_back(i);
    }
    while(dq.size()>1){
        int now=dq.back();
        dq.pop_back();
        G[now].push_back(dq.back());
        G[dq.back()].push_back(now);
    }
}

ll dfs(int now,int par)
{
    for(int i=0,p=0;i<G[now].size();++i)
        if(G[now][i]!=par)
            child[now][p++]=dfs(G[now][i],now);
    return child[now][0]+child[now][1]+1;
}
void solve()
{
    const int root=0;

    for(int i=0;i<G[root].size();++i)
        child[root][i]=dfs(G[root][i],root);

    ll MAX=0,node=0;
    for(int i=0;i<n;++i){
        if(((n-1-child[i][0])*child[i][0]+child[i][1]*(n-1-child[i][0]-child[i][1])+n-1)>MAX){
            node=i;
            MAX=((n-1-child[i][0])*child[i][0]+child[i][1]*(n-1-child[i][0]-child[i][1])+n-1);
        }
    }

    cout << MAX*2 << " " << node+1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}

