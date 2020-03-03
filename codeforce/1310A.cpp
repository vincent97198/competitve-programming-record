#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

struct item{
  ll a,t;
};

bool cmp(item x,item y)
{
    return x.a<y.a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int n;
    item arr[N];
    cin >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i].a;
    for(int i=0;i<n;++i)
        cin >> arr[i].t;

    sort(arr,arr+n,cmp);

    ll pre=-1,ans=0,sum=0;
    multiset<ll> muls;
    for(int i=0;i<n;++i){
        while(pre!=arr[i].a && sum!=0){
            sum-=*prev(muls.end());
            muls.erase(prev(muls.end()));
            ans+=sum;
            ++pre;
        }
        muls.insert(arr[i].t);
        pre=arr[i].a;
        sum+=arr[i].t;
    }
    while(muls.size()>1){
        sum-=*prev(muls.end());
        muls.erase(prev(muls.end()));
        ans+=sum;
    }
    cout << ans << endl;

    return 0;
}

