#include <bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;

int in(int x,int l,int r)
{
    if(l<=x && x<=r)
        return 1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int n,h,l,r,arr[N],dp[2][N];
    memset(dp,0,sizeof(dp));
    cin >> n >> h >> l >> r;
    for(int i=0;i<n;++i)
        cin >> arr[i];

    dp[0][0]=0;
    ll sum=0;
    for(int i=0;i<n;++i){
        sum+=arr[i];
        memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
        for(int j=0;j<=i;++j){
            dp[(i+1)&1][j]=max(dp[i&1][j]+in((sum-j)%h,l,r),dp[(i+1)&1][j]);
            if(j<n)
                dp[(i+1)&1][j+1]=max(dp[(i+1)&1][j+1],dp[i&1][j]+in((sum-j-1)%h,l,r));
        }
    }
    int ans=0;
    for(int i=0;i<=n;++i)
        ans=max(ans,dp[n&1][i]);
    cout << ans << endl;

    return 0;
}

