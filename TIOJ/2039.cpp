#include <bits/stdc++.h>
#define ll long long
#define N 2000005

using namespace std;

ll n, k, arr[N], trace[N], dp[N];

struct result{
  ll val,point;
};

void init()
{
    cin >> n >> k;
    for ( int i = 1; i <= n; ++i )
        cin >> arr[i];
}

result ans( ll mid_penalty )
{
    ll buy, preid;

    memset( trace, 0, sizeof( trace ) );
    memset( dp, 0, sizeof( dp ) );
    buy = -1e12;
    for ( int i = 1; i <= n; ++i ) {
        dp[i]=dp[i-1];
        trace[i]=trace[i-1];
        if ( dp[i] < buy + arr[i] - mid_penalty ) {
            trace[i] = trace[preid] + 1;
            dp[i] = buy + arr[i] - mid_penalty;
        }
        if ( buy < dp[i-1] - arr[i] ) {
            buy = dp[i-1] - arr[i];
            preid = i-1;
        }
    }

    return result{dp[n]+mid_penalty*trace[n],trace[n]};
}

ll solve()    //aliens
{
    ll l = 0, r = 1e10, mid_penalty;
    result r_ans=result{-1,-1},l_ans=result{-1,-1};
    while ( r - l > 0 ) {
        mid_penalty = (l + r) / 2;
        result ret=ans(mid_penalty);

        if ( ret.point <= k ){
            r = mid_penalty;
            r_ans=ret;
        }
        else{
            l = mid_penalty + 1;
            l_ans=ret;
        }
    }
    if ( r_ans.point == k )
        return r_ans.val;
    if(l_ans.point==-1)
        return r_ans.val;
    r_ans.point=abs(k-r_ans.point),l_ans.point=abs(k-l_ans.point);
    return (r_ans.val*l_ans.point+l_ans.val*r_ans.point)/(l_ans.point+r_ans.point);
}

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );

    init();
    cout << solve() << endl;

    return 0;
}
