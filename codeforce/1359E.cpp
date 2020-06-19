#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

ll n,k,X,Y,ans=0,fact[N];
const ll MOD = 998244353;

void exgcd(ll a,ll b)
{
    if(b==0){
        X=1,Y=0;
        return ;
    }

    exgcd(b,a%b);
    int t=X;
    X=Y;
    Y=t-a/b*Y;
}

ll mul(ll a,ll b)
{
    return (a*b)%MOD;
}

ll inv(ll a)
{
    exgcd(a,MOD);
    return X;
}
/*
 * 1/a=x (mod MOD)
 * 1=ax mod MOD
 * 1=ax-MOD*y
 */

ll calc(ll a,ll b)
{
    return (b>a?0:mul(fact[a],inv(fact[a-b]*fact[b])));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    cin >> n >> k;
    fact[0]=1;
    for(int i=1;i<N;++i)    fact[i]=(fact[i-1]*i)%MOD;
    for(int i=1;i<=n;++i){
        ll tmp=n/i;
        ans+=calc(tmp-1,k-1);
        ans%=MOD;
    }
    cout << (ans+MOD)%MOD << endl;

    return 0;
}
