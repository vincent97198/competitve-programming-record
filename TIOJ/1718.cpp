#include <bits/stdc++.h>
#define ll long long
#define N 55

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int m,n,p,cost[N][N],power[N][N],dp[N][10005];
	cin >> m >> n >> p;

	for(int i=0;i<n;++i)
		for(int j=0;j<p;++j)
			cin >> cost[i][j] >> power[i][j];

	memset(dp,0,sizeof(dp));
	
	for(int j=0;j<p;++j)
		dp[0][cost[0][j]]=power[0][j];

	for(int i=1;i<n;++i){
		for(int j=0;j<p;++j){
			for(int k=m-cost[i][j];k>=0;--k){
				dp[i][k+cost[i][j]]=max(dp[i][k+cost[i][j]],dp[i-1][k]+power[i][j]);
			}
		}
	}

	int MAX=0;
	for(int k=m;k>=0;--k)
		MAX=max(MAX,dp[n-1][k]);

	cout << MAX << endl;

	return 0;
}
