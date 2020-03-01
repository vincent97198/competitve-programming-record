#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

ll n,X,Y;
const ll MOD=1000000007;

void exgcd(ll a,ll b)
{
    if(b==0){
        X=1;    Y=0;
        return ;
    }
    exgcd(b,a%b);
    ll tmp=X;
    X=Y;
    Y=tmp-a/b*Y;
}

ll inv(ll a)
{
    exgcd(a,MOD);
    return (X%MOD)+MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    cin >> n;
    ll ans=0,now=1;
    for(int i=0;i<=n;++i){
        now=(now*(n+1+i))%MOD;
        now=(now*inv(i+1))%MOD;
        ans=(ans+now)%MOD;
    }
    cout << ans%MOD << endl;

    return 0;
}

