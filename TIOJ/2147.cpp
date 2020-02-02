#include <bits/stdc++.h>
#define ll long long
#define N 205

using namespace std;

ll n,k,num[N];
ll dp[2][N][N],MIN[2][N];
vector<ll> v;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    cin >> n >> k;
    for(int i=1;i<=n;++i){
        cin >> num[i];
        v.push_back(num[i]);
    }
    sort(v.begin(),v.end());	v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;++i)
        num[i]=distance(v.begin(),lower_bound(v.begin(),v.end(),num[i]))+1;

    for(int i=1;i<=n;++i){
        for(int j=1;j<num[i];++j)
            dp[0][i][j]=1e18;
        for(int j=num[i];j<=v.size();++j)
            dp[0][i][j]=v[j-1]-v[num[i]-1];
    }

    int cur=1,now=0;
    for(int i=2;i<=k;++i){
        memset(dp[cur],0x3f,sizeof(dp[cur]));
        memset(MIN,0x3f,sizeof(MIN));
        for(int j=1;j<=n;++j){
            for(int c=num[j];c<=v.size();++c)
                dp[cur][j][c]=min(dp[cur][j][c],MIN[now^1][c]+v[c-1]-v[num[j]-1]);
            for(int c=1;c<=v.size();++c)
                MIN[now][c]=min( dp[cur^1][j][c], min(MIN[now^1][c],MIN[now][c-1]) );
			now^=1;
        }
        cur^=1;
    }

    cur^=1;

    ll ans=1e18;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=v.size();++j)
            ans=min(ans,dp[cur][i][j]);
    }


    cout << ans << endl;

    return 0;
}

