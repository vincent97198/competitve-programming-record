#include <bits/stdc++.h>
#define N 100003
#define ll long long

using namespace std;

ll n,m;
pair<ll,ll> arr[N];
pair<ll,ll> prefix[N];

void init()
{
    cin >> n >> m;
    for(int i=1;i<=m;++i){
        cin >> arr[i].first >> arr[i].second;
        prefix[i].first=arr[i].first;
    }
    sort(prefix+1,prefix+m+1,greater<pair<ll,ll>>());

    prefix[0]={0,0};
    for(int i=1;i<=m;++i)
        prefix[i].second=prefix[i-1].second+prefix[i].first;

}

void solve()
{
    ll ans=0;
    for(int i=1;i<=m;++i){
        int l=0,r=m,mid;
        while(r-l>1){
            mid=(l+r)/2;
            if(prefix[mid].first>=arr[i].second)
                l=mid;
            else
                r=mid-1;
        }
        if(prefix[r].first>=arr[i].second)
            mid=r;
        else
            mid=l;
        if(mid>n){
            ans=max(ans,prefix[n].second);
            continue;
        }
        if (arr[i].second<=arr[i].first)
            ans=max(ans,prefix[mid].second+(n-mid)*arr[i].second);
        else
            ans=max(ans,prefix[mid].second+(n-mid-1)*arr[i].second+arr[i].first);
    }
    cout << ans << endl;
}

int main()
{
    int t;  cin >> t;
    while(t--){
        init();
        solve();
    }
   // cout << "\n" << 587575696+18LL*945418070 << endl;
    return 0;
}

/*
 *
 */
