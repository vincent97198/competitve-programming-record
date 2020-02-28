#include <bits/stdc++.h>
#define ll long long
#define N 3000

using namespace std;

int n,m;
ll arr[N],dp[N][2];

void init()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i)
        cin >> arr[i];
    for(int i=2;i<=n;++i)
        arr[i]+=arr[i-1];
}

ll calc(int a,int b,int p)
{
    return (dp[a][p]-dp[b][p]+arr[a]*arr[a]-arr[b]*arr[b])/(arr[a]-arr[b]);
}

void solve()
{
    for(int i=1;i<=n;++i)
        dp[i][1]=arr[i]*arr[i];

    for(int i=2;i<=m;++i){
        int now=i&1;
        deque<int> dq;
        dq.push_front(0);
        for(int j=1;j<=n;++j){
            while(dq.size()>1 && calc(dq[dq.size()-2],dq.back(),!now)<2*arr[j]){
                dq.pop_back();
            }
            dp[j][now]=dp[dq.back()][!now]+(arr[j]-arr[dq.back()])*(arr[j]-arr[dq.back()]);
            while(dq.size()>1 && calc(dq[1],dq.front(),!now)>=calc(dq.front(),j,!now)){
                dq.pop_front();
            }
            dq.push_front(j);
        }
    }
    cout << dp[n][m&1]*m-arr[n]*arr[n] << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}

