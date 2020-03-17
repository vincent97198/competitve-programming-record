#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

ll n,arr[N],sum[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    while(cin >> n){
        ll SUM=0;
        for(int i=0;i<n;++i){
            cin >> arr[i];
            if(arr[i]>0)
                arr[i]=1;
            else if(arr[i]<0)
                arr[i]=-1;
            else
                arr[i]=0;
            SUM+=arr[i];
        }


        for(int i=n-1;i>=0;--i)
            sum[i]=sum[i+1]+arr[i];

        map<ll,ll> mp;
        mp.clear();
        for(int i=0;i<=n;++i)
            mp[sum[i]]=i;

        ll now=0,ans=0;
        for(int i=0;i<n;++i){
            ans=max(ans,mp[SUM-now]-i);
            now+=arr[i];
        }
        cout << ans << '\n';
        for(int i=0;i<n+5;++i){
            sum[i]=0;
            arr[i]=0;
        }
    }

    return 0;
}

