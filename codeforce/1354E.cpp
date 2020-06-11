#include <bits/stdc++.h>
#define N 5005

using namespace std;

int n,m,n1,n2,n3,part=0,all=0,cnt=0;
vector<int> G[N],Part[N];
bool Color[N],dp[N][N];
bool vis[N];

void dfs(int now,bool color)
{
    part+=color;
    ++all;
    Part[cnt].push_back(now);
    Color[now]=color;
    vis[now]=true;
    for(int next:G[now]){
        if(!vis[next]){
            vis[next]=true;
            dfs(next,!color);
        }
        else if(Color[next]==color){
            cout << "NO\n" << endl;
            exit(0);
        }
    }
}

void init()
{
    cin >> n >> m >> n1 >> n2 >> n3;
    for(int i=0;i<m;++i){
        int u,v;    cin >> u >> v;
        G[u].push_back(v);  G[v].push_back(u);
    }
}

void solve()
{
    vector<int> tmp,tmpALL;
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            dfs(i,false);
            tmp.push_back(part);    tmpALL.push_back(all);
            part=0,all=0;
            ++cnt;
        }
    }

    dp[0][0]=true;
    for(int i=0;i<tmp.size();++i){
        for(int j=N-1;j>=0;--j){
            if(j>=tmp[i])
                dp[i+1][j]|=dp[i][j-tmp[i]];
            if(j>=tmpALL[i]-tmp[i])
                dp[i+1][j]|=dp[i][j-tmpALL[i]+tmp[i]];
        }
    }
    if(dp[tmp.size()][n2]){
        cout << "YES\n";
        int ans[N]; memset(ans,0,sizeof(ans));
        for(int i=cnt-1;i>=0;--i){
            if(n2>=tmp[i] && dp[i][n2-tmp[i]]){
                for(int j:Part[i])
                    if(Color[j])
                       ans[j]=true;
                n2-=tmp[i];
            }
            else{
                for(int j:Part[i])
                    if(!Color[j])
                        ans[j]=true;
                n2-=(tmpALL[i]-tmp[i]);
            }
        }
        for(int i=1;i<=n;++i){
            if(ans[i]==0){
                cout << (n1>0?1:3);
                --n1;
            }
            else
                cout << 2;
        }
        cout << endl;
    }
    else{
        cout << "NO\n";
    }
}

int main()
{
   init();
   solve();
}
