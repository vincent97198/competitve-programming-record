#include <bits/stdc++.h>
#define N 200005

using namespace std;

int dp[N][3],pos[N];

int DP(int now,int state)
{
	if(dp[now][state]!=-1)	return dp[now][state];
	if(now==0)	return 0;
	dp[now][state]=DP(now-1,0)+(pos[now]!=state);
	for(int i=1;i<=state;++i)
		dp[now][state]=min( dp[now][state], DP(now-1,i)+(pos[now]!=state) );
	return dp[now][state];
}

int main()
{
	int k[3],n=0;
	for(int i=0;i<3;++i){
		cin >> k[i];
		n+=k[i];
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<k[i];++j){
			int tmp;	cin >> tmp;
			pos[tmp]=i;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout << min( DP(n,0) , min( DP(n,1),DP(n,2) ) ) << endl;
}
