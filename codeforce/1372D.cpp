#include <bits/stdc++.h>
#define N 200003
#define ll long long

using namespace std;

int main()
{
    int n;  cin >> n;
    ll a[N];
    for(int i=0;i<n;++i)    cin >> a[i];
    ll cnt=0;
    for(int i=0;i<(n+1)/2;++i)
        cnt+=a[2*i];
    ll ans=cnt;
    for(int i=0;i<n;++i){
        cnt-=a[(2*i)%n];
        cnt+=a[2*(i+(n+1)/2)%n];
        ans=max(cnt,ans);
    }
    cout << ans << endl;

    return 0;
}

/*
 *
 */
