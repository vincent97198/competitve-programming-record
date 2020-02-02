#include <bits/stdc++.h>
#define ll long long
#define N 205

using namespace std;

ll n,k,num[N];
ll dp[2][N][N],BIT[N];
vector<ll> v;

inline int lowbit(int x)
{
	return x&(-x);
}

void add(int pos,ll val)
{
	for(;pos<N;pos+=lowbit(pos))
		BIT[pos]=min(BIT[pos],val);
}

ll query(int pos)
{
	ll tmp=1e18;
	for(;pos>0;pos-=lowbit(pos))
		tmp=min(BIT[pos],tmp);
	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	
	cin >> n >> k;
	for(int i=0;i<n;++i){
		cin >> num[i];
		v.push_back(num[i]);
	}
	sort(v.begin(),v.end());	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;++i)
		num[i]=distance(v.begin(),lower_bound(v.begin(),v.end(),num[i]))+1;
	
	for(int i=0;i<n;++i){
		for(int j=1;j<num[i];++j)
			dp[0][i][j]=1e18;
		for(int j=num[i];j<=v.size();++j)
			dp[0][i][j]=v[j-1]-v[num[i]-1];
	}

	int cur=1;
	for(int i=2;i<=k;++i){
		memset(BIT,0x3f,sizeof(BIT));
		memset(dp[cur],0x3f,sizeof(dp[cur]));
		for(int j=0;j<n;++j){
			for(int c=num[j];c<=v.size();++c)
				dp[cur][j][c]=min(dp[cur][j][c],query(c)+v[c-1]-v[num[j]-1]);
			for(int c=1;c<=v.size();++c)
				add(c,dp[cur^1][j][c]);
		}
		cur^=1;
	}
	
	cur^=1;

	ll ans=1e18;
	for(int i=0;i<n;++i){
		for(int j=1;j<=v.size();++j)
			ans=min(ans,dp[cur][i][j]);
	}
	
	
	cout << ans << endl;

	return 0;
}
