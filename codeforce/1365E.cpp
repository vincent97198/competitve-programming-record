#include <bits/stdc++.h>
#define ll long long
#define N 505

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n;  cin >> n;
    ll a[N];
    a[0]=0,a[1]=0;
    n+=2;
    for(int i=2;i<n;++i)    cin >> a[i];

    ll ans=0;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            for(int k=j+1;k<n;++k)
                ans=max(ans,a[i]|a[j]|a[k]);
    cout << ans << endl;

    return 0;
}

