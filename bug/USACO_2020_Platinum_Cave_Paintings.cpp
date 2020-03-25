#include <bits/stdc++.h>
#define ll long long
#define N 1005

using namespace std;

const ll MOD=1000000007;
int n,m,cnt=0,boss[N*N],group[N*N],ans_group[N*N],dx[2]={0,-1},dy[2]={-1,0};
bool mp[N][N];

ll POWER(ll x,ll P,ll MOD)
{
    if(P<0)
        return 0;
    ll ret=1;
    while(P>0){
        if(P&1)
            ret=(ret*x)%MOD;
        x=(x*x)%MOD;
        P>>=1;
    }
    return ret;
}

int find(int x)
{
    if(boss[x]==x)
        return x;
    else{
        boss[x]=find(boss[x]);
        return boss[x];
    }
}

void merge(int a,int b)
{
    a=find(a),b=find(b);
    if(a==b)    return;
    if(group[b]>group[a])
        swap(a,b);
    boss[b]=a;
    group[a]+=group[b];
    ans_group[a]=%MOD;
    --cnt;
}

void init()
{
    cin >> n >> m;

    char ch;
    for(int i=n;i>=1;--i){
        for(int j=1;j<=m;++j){
            cin >> ch;
            if(ch=='.')
                mp[i][j]=true;
        }
    }
    for(int i=0;i<N;++i)
        boss[i]=i,group[i]=1;
}

void solve()
{
    ll ans=0;
    bool flag;
    for(int i=1;i<=n;++i){
        flag=false;
        for(int j=1;j<=m;++j){
            if(mp[i][j]){
                flag=true;
                int now=i*(m+1)+j;
                ++cnt;
                for(int k=0;k<2;++k){
                    if(mp[i+dx[k]][j+dy[k]]){
                        int tmp=(i+dx[k])*(m+1)+j+dy[k];
                        merge(now,tmp);
                    }
                }
            }
        }
        if(flag)
            ans=(ans+POWER(2,cnt,MOD)-1)%MOD;
    }
    cout << (ans+1)%MOD << endl;
}

int main()
{
    //freopen("cave.in","r",stdin);
    //freopen("cave.out","w",stdout);
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );

    init();
    solve();

    return 0;
}
