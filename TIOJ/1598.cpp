#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

ll n,B,P[N],MAX=0,dp[10*N];

bool check(ll t)
{
    ll l=0,r=1e6,lmid,rmid,mid;
    while(r-l>0){
        lmid=(2*l+r)/3; rmid=(l+2*r)/3;
        if(t*(lmid+1)-dp[lmid+1]>t*(rmid+1)-dp[rmid+1])
            r=rmid;
        else
            l=lmid+1;
    }

    ll r_save=r,B_tmp=B;
    for(int i=0;i<n;++i){
        r=r_save;   l=0;
        while(r-l>0){
            mid=(l+r)/2;
            if(t*(mid+1)-dp[mid+1]>=P[i])
                r=mid;
            else
                l=mid+1;
        }
        B_tmp-=r;
    }
    return B_tmp>=0;
}

void init()
{
    cin >> n >> B;
    for(int i=0;i<n;++i){
        cin >> P[i];
        MAX=max(MAX,P[i]);
    }

    for(int i=2;i<=1e6+5;++i)
        dp[i]=dp[i-i/2]+dp[i/2]+i;
}

void solve()
{
    ll l=2,r=MAX,mid;
    while(r-l>0){
        mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout << l << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    init();
    solve();

    return 0;
}

/*
5 7
43 23 12 32 21          13

6 5
3 12 31 43 5 90         25

6 55
3 12 31 43 5 90         8
 */

/*
   solution

dp(t, 0) = t - 0
dp(t, 1) = 2t - 2
dp(t, 2) = 3t - 5
dp(t, 3) = 4t - 8
dp(t, 4) = 5t - 12
dp(t, 5) = 6t - 16
dp(t, 6) = 7t - 20

dp[t][1]=0;
dp[t][k]=dp[t][k-k/2]+dp[t][k/2]+k;

*/
