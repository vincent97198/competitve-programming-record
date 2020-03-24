#include <bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;

bool dp[N][N];
int dp2[N];
int n,A,B;
ll ans,arr[N],sum=0;

void init()
{
	cin >> n >> A >> B;
	for(int i=1;i<=n;++i){
		cin >> arr[i];
		sum+=arr[i];
	}
}

void solve()
{
	int maxn=log2(sum)+1;
	
	for(int i=maxn;i>=0;--i){
		ll res=( ans|( ((ll)1<<i)-(ll)1 ) );

		memset(dp,0,sizeof(dp));
		dp[0][0]=true;

		for(int j=1;j<=n;++j){	//第J個數
			for(int k=1;k<=min(j,B);++k){	//分段數
				ll SUM=0;
				for(int t=j-1;t>=k-1;--t){	//分割點
					SUM+=arr[t+1];
					if(dp[t][k-1] && ((SUM|res)==res) ){
						dp[j][k]=true;
						break;
					}
				}
			}
		}

		bool flag=false;
		for(int j=A;j<=B;++j){
			if(dp[n][j]){
				flag=true;
				break;
			}
		}
		if(!flag)
			ans|=((ll)1<<i);
	}
}

void solve2()
{
	int maxn=log2(sum)+1;

	for(int i=maxn;i>=0;--i){
		ll res=( ans|( ((ll)1<<i)-(ll)1 ) );
		
		memset(dp2,0x7f,sizeof(dp2));
		dp2[0]=0;

		for(int j=1;j<=n;++j){
			ll SUM=0;
			for(int k=j-1;k>=0;--k){
				SUM+=arr[k+1];
				if((SUM|res)==res)
					dp2[j]=min(dp2[j],dp2[k]+1);
			}
		}
		if(dp2[n]>B)
			ans|=((ll)1<<i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	init();
	if(A==1)
		solve2();
	else
		solve();

	cout << ans << endl;

	return 0;
}
