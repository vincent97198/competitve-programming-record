#include <bits/stdc++.h>
#pragma GCC optomize("Ofast","fast-math");
#define N 100005

using namespace std;

int main()
{
	int n;
	const long double pi=acos(-1);
	const int MAXN=100;
	cin >> n;
	cout << fixed << setprecision(10);
	for(int i=0;i<n;++i){
	    long double a;  cin >> a;
	    long double R=0.5/cos((180-180/a)/2*pi/180),ans=1e18;
	    for(long double j=0;j<MAXN;j=j+1){
	        long double r=-1e18,l=1e18,u=-1e18,d=1e18;
	        for(long double k=0;k<2*a;k=k+1){
	            long double theta=pi/a*k+pi*j/(MAXN*2);
                r=max(r,R*cos(theta));
                l=min(l,R*cos(theta));
                u=max(u,R*sin(theta));
                d=min(d,R*sin(theta));
	        }
	        ans=min(ans,max(r-l,u-d));
	    }
	    cout << ans << endl;
	}

	return 0;
}

