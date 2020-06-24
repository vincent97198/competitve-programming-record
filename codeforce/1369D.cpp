#include <bits/stdc++.h>
#define ll long long
#define N 2000005

using namespace std;

ll DP[N][2];
const ll MOD = 1000000007;

ll dp(int x,int status)
{
    if(DP[x][status]!=-1)
        return DP[x][status];

    if(status)
        return DP[x][status]=(2*dp(x-2,0)+dp(x-1,0)+4)%MOD;
    else
        return DP[x][status]=( 2*max(dp(x-2,1),dp(x-2,0)) + max(dp(x-1,1),dp(x-1,0)) )%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    memset(DP,-1,sizeof(DP));
    DP[1][0]=DP[1][1]=DP[2][0]=DP[2][1]=DP[3][0]=0;
    DP[3][1]=4;

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        cout << max(dp(n,0),dp(n,1)) << endl;
    }

    return 0;
}
