#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int arr[N],sum=0;
        arr[0]=0;
        for(int i=1;i<=n;++i){
            char ch;    cin >> ch;
            sum+=(ch-'0');
            arr[i]=sum;  arr[i]-=i;
        }
        map<ll,ll> mp;
        for(int i=0;i<=n;++i)   ++mp[arr[i]];
        ll ans=0;
        for(auto iter=mp.begin();iter!=mp.end();++iter)
            ans+=(iter->second)*(iter->second-1)/2;
        cout << ans << endl;
    }
    return 0;
}
