#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

ll n,a,b,c,arr[N],dp[N],sum[N],dq[N];

void init()
{
    cin >> n >> a >> b >> c;
    for(int i=1;i<=n;++i){
        cin >> arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
}

double slope(int j,int k)
{
    return (dp[j]-dp[k]+a*(sum[j]*sum[j]-sum[k]*sum[k])+b*(sum[k]-sum[j]))/double(2*a*(sum[j]-sum[k]));
}

void solve()
{
    ll l=1,r=1;
    for(int i=1;i<=n;++i){
        while(r>l && slope(dq[l],dq[l+1])<=(double)sum[i])
            ++l;

        ll x=sum[i]-sum[dq[l]];

        dp[i]=dp[dq[l]]+a*x*x+b*x+c;

        while(r>=l && slope(dq[r-1],dq[r])>=slope(dq[r],i))
            --r;
        dq[++r]=i;
    }
    cout << dp[n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}

