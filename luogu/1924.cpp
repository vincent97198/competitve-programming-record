#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
#define N 505

using namespace std;

int n,m,k,dp[2][59050],pre[15],now[15],base[] = { 0 , 1 , 3 , 9 , 27 , 81 , 243 , 729 , 2187, 6561 , 19683 , 59049 };;
bool color[505][15];

inline int trans(int *t)
{
    int tmp=0,POWER=1;
    for(int i=1;i<=m;++i)
        tmp+=t[i]*POWER,POWER*=3;
    return tmp;
}

void init()
{
    memset(color,0,sizeof(color));
    memset(dp,0xff,sizeof(dp));

    cin >> n >> m >> k;
    int tmpx,tmpy;
    for(int i=0;i<k;++i){
        cin >> tmpx >> tmpy;
        color[tmpx][tmpy]=true;
    }
}

void dfs(int i,int j,int cur,int s)
{
    dp[i&1][s]=max(dp[i&1][s],cur);
    if(j>=m)    return ;
    if(!pre[j] && !pre[j+1] && !now[j] && !now[j+1]){
        now[j]=now[j+1]=2;
        int k=trans(now); dfs(i,j+2,cur+1,k);
        now[j]=now[j+1]=0;
    }
    if(j<m-1 && !now[j] && !now[j+1] && !now[j+2]){
        now[j]=now[j+1]=now[j+2]=2;
        int k=trans(now);   dfs(i,j+3,cur+1,k);
        now[j]=now[j+1]=now[j+2]=0;
    }
    dfs(i,j+1,cur,s);
}

void solve()
{
    for(int i=1;i<=m;++i)
        pre[i]=2;
    dp[0][(int)pow(3,m)-1]=0;
    for(int i=1;i<=n;++i){
        memset(dp[i&1],0xff,sizeof(dp[i&1]));
        for(int j=0;j<base[m+1];++j){
            if(dp[(i+1)&1][j]!=-1){
                int tmpJ=j;
                for(int i=1;i<=m;++i)
                    pre[i]=tmpJ%3,tmpJ/=3;
                for(int k=1;k<=m;++k){
                    if(color[i][k])
                        now[k]=2;
                    else
                        now[k]=max(0,pre[k]-1);
                }
                dfs(i,1,dp[(i+1)&1][j],trans(now));
            }
        }
    }
    int ans=0;
    for(int i=0;i<base[m+1];++i)
        ans=max(ans,dp[n&1][i]);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        init();
        solve();
    }

    return 0;
}
	//註解版： https://ideone.com/ssk7KU
