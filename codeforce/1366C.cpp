#include <bits/stdc++.h>
#define ll long long
#define N 35

using namespace std;

bool M[N][N],vis[N][N];

int main()
{
    int t;  cin >> t;
    while(t--){
        memset(vis,0,sizeof(vis));
        int n,m,ans=0;    cin >> n >> m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin >> M[i][j];
        queue<pair<int,int>> q[2*N][2];
        q[0][0].push(make_pair(1,1));   q[0][1].push(make_pair(n,m));
        int zero=M[1][1]+M[n][m],one=2-M[1][1]-M[n][m];
        for(int i=1;i<(n+m-1)/2;++i){
            ans+=min(zero,one); zero=one=0;
            for(int j=0;j<2;++j){
                while(!q[i-1][j].empty()){
                    pair<int,int> pr=q[i-1][j].front(); q[i-1][j].pop();
                    if(pr.first+(1-2*j)<=n && pr.first+(1-2*j)>=1 && !vis[pr.first+(1-2*j)][pr.second]){
                        q[i][j].push(make_pair(pr.first+(1-2*j),pr.second));
                        zero+=M[pr.first+(1-2*j)][pr.second];
                        one+=(1-M[pr.first+(1-2*j)][pr.second]);
                        vis[pr.first+(1-2*j)][pr.second]=true;
                    }
                    if(pr.second+(1-2*j)<=m && pr.second+(1-2*j)>=1 && !vis[pr.first][pr.second+(1-2*j)]){
                        q[i][j].push(make_pair(pr.first,pr.second+(1-2*j)));
                        zero+=M[pr.first][pr.second+(1-2*j)];
                        one+=(1-M[pr.first][pr.second+(1-2*j)]);
                        vis[pr.first][pr.second+(1-2*j)]=true;
                    }
                }
            }
        }
        cout << ans+min(zero,one) << endl;
    }
    return 0;
}

