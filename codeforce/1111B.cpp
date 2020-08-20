#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
    cout << fixed << setprecision(7);
    ll n,k,m;  cin >> n >> k >> m;
    ll a[N],sum=0;
    for(int i=0;i<n;++i){
        cin >> a[i];
        sum+=a[i];
    }
    sort(a,a+n);

    long double ans=0;
    for(ll i=0;i<=min(m,n-1);++i){
        if(i>0) sum-=a[i-1];
        ans=max(ans,(long double)(sum+min(m-i,(n-i)*k))/(n-i));
    }
    cout << ans << endl;

    return 0;
}

/*
 * 
 */
