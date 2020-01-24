#include <bits/stdc++.h>
#define ll long long
#define N 105

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n,dp[N][N/2][2],a[N];

	cin >> n;

	for(int i=1;i<=n;++i)
		cin >> a[i];

	memset(dp,0x7f,sizeof(dp));
	dp[0][0][1]=0;	dp[0][0][0]=0;

	for(int i=1;i<=n;++i){
		for(int j=0;j<i && j<N/2;++j){
			for(int k=0;k<2;++k){
				if(a[i]==0){
					for(int p=0;p<2;++p){
						dp[i][j-(p-1)][p]=min(dp[i][j-(p-1)][p],dp[i-1][j][k]+(k!=p));
					}
				}
				else{
					if(a[i]%2==0)
						dp[i][j+1][0]=min(dp[i][j+1][0],dp[i-1][j][k]+(k!=0));
					else
						dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][k]+(k!=1));
				}
			}
		}
	}

	cout << min(dp[n][n/2][0],dp[n][n/2][1]) << endl;

	return 0;
}
