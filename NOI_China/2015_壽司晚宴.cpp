#include <bits/stdc++.h>
#define N 505
#define ll long long

using namespace std;

struct item{
  ll val=0,S=0,big=-1;
};

item arr[N];
ll n,MOD,dp[300][300],f1[300][300],f2[300][300],prime[8]={2,3,5,7,11,13,17,19};

bool cmp(item a,item b)
{
    return a.big<b.big;
}

void init()
{
    cin >> n >> MOD;

    for(int i=1;i<n;++i){
        int num=i+1;
        arr[i].val=num;
        for(int j=0;j<8;++j){
            if(num%prime[j]==0){
                arr[i].S|=(1<<j);
                while(num%prime[j]==0){
                    num/=prime[j];
                }
            }
            if(num!=1)
                arr[i].big=num;
            else
                arr[i].big=-1;
        }
    }
    sort(arr+1,arr+n,cmp);
}

void solve()
{
    dp[0][0]=1;
    for(int i=1;i<n;++i){
        if(i==1||arr[i].big!=arr[i-1].big||arr[i].big==-1){
            memcpy(f1,dp,sizeof(f1));
            memcpy(f2,dp,sizeof(f2));
        }
        for(int j=255;j>=0;--j){
            for(int k=255;k>=0;--k){
                if(j&k) continue;
                if((arr[i].S&j)==0)
                    f2[j][k|arr[i].S]=(f2[j][k|arr[i].S]+f2[j][k])%MOD;
                if((arr[i].S&k)==0)
                    f1[j|arr[i].S][k]=(f1[j|arr[i].S][k]+f1[j][k])%MOD;
            }
        }
        if(i==n-1||arr[i].big!=arr[i+1].big||arr[i].big==-1){
            for(int j=0;j<=255;++j){
                for(int k=0;k<=255;++k){
                    if(j&k) continue;
                    dp[j][k]=((f1[j][k]-dp[j][k]+f2[j][k])%MOD+MOD)%MOD;
                }
            }
        }
    }
    ll ans=0;
    for(int j=0;j<=255;++j){
        for(int k=0;k<=255;++k){
            if((j&k)==0 && dp[j][k])
                ans=(ans+dp[j][k])%MOD;
        }
    }
    cout << ans << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    init();
    solve();

    return 0;
}
