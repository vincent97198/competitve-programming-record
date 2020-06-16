#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

vector<int> G[N],ans;
int depth[N],par[N];

void dfs(int now,int parent)
{
    for(int next:G[now]){
        if(next==parent)   continue;
        if(depth[next]==0){
            depth[next]=depth[now]+1;
            par[next]=now;
            dfs(next,now);
        }
        else if(depth[next]<depth[now]){
            int tmp=now;
            while(tmp!=next){
                ans.emplace_back(tmp);
                tmp=par[tmp];
            }
            ans.emplace_back(tmp);
            cout << "2\n" << ans.size() << endl;
            for(int i:ans)
                cout << i << " ";
            exit(0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n,m,k;    cin >> n >> m >> k;
    for(int i=0;i<m;++i){
        int u,v;    cin >> u >> v;
        if(u<=k && v<=k)
            G[u].emplace_back(v),G[v].emplace_back(u);
    }
    for(int i=1;i<=k;++i){
        if(depth[i]==0){
            depth[i]=1;
            dfs(i,i);
        }
    }
    vector<int> ans2[2];
    for(int i=1;i<=k;++i)
        ans2[depth[i]&1].emplace_back(i);
    k=(k+1)/2;
    cout << "1\n";
    for(int i=0;i<k;++i)
        if(ans2[0].size()>ans2[1].size())
            cout << ans2[0][i] << " ";
        else
            cout << ans2[1][i] << " ";
    cout << endl;

    return 0;
}

