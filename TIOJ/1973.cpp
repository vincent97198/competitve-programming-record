#include <bits/stdc++.h>
#define ll long long
#define N 5005

using namespace std;

const ll MOD=1000000007;
ll dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	char type;
	int n,k,tmp,sum=0;
	cin >> type >> n >> k;
	for(int i=0;i<k;++i){
		cin >> tmp;
		sum+=tmp;
	}

	memset(dp,0,sizeof(dp));
	if(type=='U'){
		n-=sum;

		dp[0][0]=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=i;++j)
				dp[i][j]=(dp[i-1][j-1]+dp[i-j][j])%MOD;
	}
	else{
		dp[k][k]=1;
		for(int i=k;i<=n;++i){
			for(int j=k;j<=i;++j){
				if(i==k && j==k)
					continue;
				else
					dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*j)%MOD;
			}
		}
	}

	ll ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+dp[n][i])%MOD;
	cout << ans << endl;

	return 0;
}
