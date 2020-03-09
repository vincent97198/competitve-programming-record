#include <bits/stdc++.h>
#define N 10005
#define ll long long

using namespace std;

struct item{
  int t,w;
};

int T,M;
item arr[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    cin >> T >> M;
    ll dp[100005];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<M;++i)
        cin >> arr[i].t >> arr[i].w;
    ll ans=0;
    for(int i=0;i<M;++i){
        for(int j=0;j+arr[i].t<=T;++j){
            dp[j+arr[i].t]=max(dp[j+arr[i].t],dp[j]+arr[i].w);
            ans=max(ans,dp[j+arr[i].t]);
        }
    }
    cout << ans << endl;

    return 0;
}
