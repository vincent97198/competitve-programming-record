#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        int n,k;    cin >> n >> k;
        int arr[200005];
        for(int i=1;i<=n*k;++i)
            cin >> arr[i];
        
        int ans=0;
        for(int i=n*k-(n-ceil(n/2.0)),cnt=0;cnt<k;++cnt,i-=(n-ceil(n/2.0)+1))
            ans+=arr[i];
        cout << ans << '\n';
    }

    
    return 0;
}