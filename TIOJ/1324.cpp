#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

int n;
ll X[N],k,x,y;

ll power(ll x,ll POWER,ll MOD)
{
	ll ret=1;
	while(POWER>0){
		if(POWER&1)
			ret=(ret*x)%MOD;
		x=(x*x)%MOD;
		POWER>>=1;
	}
	return ret%=MOD;
}

void exgcd(ll a,ll b)
{
	if(b==0){
		x=1;
		y=0;
	}

	exgcd(b,a%b);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
}

ll gcd(ll a,ll b)
{
	return (b==0)?a:gcd(b,a%b);
}

void init()
{
	for(int i=0;i<n;++i)
		cin >> X[i];
	cin >> k;
}

ll dfs(ll now,ll MOD)
{
	if(now==n-1)
		return X[now]%MOD;

	ll nextMOD=MOD,tmp=MOD;
	for(ll i=2;i*i<=tmp;++i){
		if(tmp%i==0)
			nextMOD=nextMOD/i*(i-1);
		while(tmp%i==0){
			tmp/=i;
		}
	}
	if(tmp!=1)
		nextMOD=nextMOD/tmp*(tmp-1);

	ll GCD=gcd(MOD,X[now]);
	ll nextPOWER=dfs(now+1,nextMOD);
	if(GCD==1)
		return power(X[now],nextPOWER,MOD);
	else{
		vector<ll> v;
		do{
			v.push_back(GCD);
			X[now]/=GCD;
			GCD=gcd(MOD,X[now]);
		}while(GCD!=1);

		ll ret=power(X[now],nextPOWER,MOD);
		for(int i=0;i<v.size();++i){
			exgcd(v[i],-MOD/v[i]);
			ret=(ret*((v[i]*x*power(v[i],nextPOWER,MOD/v[i]))%MOD))%MOD;
		}

		return ret;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	while(cin >> n && n!=0){
		init();
		cout << dfs(0,k) << endl;
	}

	return 0;
}
