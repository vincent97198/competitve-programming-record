#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

struct pos{
	ll x,y;
}a[N];

ll calc(int p,int q)
{
	return (a[p].x-a[q].x)*(a[p].x-a[q].x)+(a[p].y-a[q].y)*(a[p].y-a[q].y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	ll n;
	cin >> n;
	if(n%2==1){
		cout << "NO" << endl;
		return 0;
	}

	bool flag=true;
	for(int i=0;i<n;++i){
		cin >> a[i].x >> a[i].y;
	}
	ll tmp=calc(0,n-1);
	for(int i=0;i<n-1;++i){
		if( calc(i,i+1)!=tmp  ){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}
