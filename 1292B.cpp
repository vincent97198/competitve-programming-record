#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	ll x0,y0,ax,ay,bx,by,xs,ys,t;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

	vector<ll> X,Y;
	X.push_back(x0);	Y.push_back(y0);
	while(true){
		ll bound=0;
		bound+=(X[(int)X.size()-1]-xs)+(Y[(int)Y.size()-1]-ys);
		if(bound>t){
			X.pop_back();	Y.pop_back();
			break;
		}
		X.push_back(X[(int)X.size()-1]*ax+bx);
		Y.push_back(Y[(int)Y.size()-1]*ay+by);
	}

	int ans=0;
	for(int i=0;i<X.size();++i){
		for(int j=i;j<Y.size();++j){
			ll L=abs(xs-X[i])+abs(ys-Y[i]),R=abs(xs-X[j])+abs(ys-Y[j]);
			if( min(L,R)+(X[j]-X[i])+(Y[j]-Y[i])<=t )
				ans=max(ans,j-i+1);
		}
	}

	cout << ans << endl;

	return 0;
}
