#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int n,dp[30],ans[N];
	string s;
	cin >> n >> s;


	int MAX=0;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;++i)
		ans[i]=1;
	for(int i=0;i<n;++i){
		for(int j=25;j>s[i]-'a';--j)
			ans[i]=max(ans[i],dp[j]+1);
		dp[s[i]-'a']=max(ans[i],dp[s[i]-'a']);
		MAX=max(MAX,ans[i]);
	}

	cout << MAX << endl;
	for(int i=0;i<n;++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}
