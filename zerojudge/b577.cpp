#include <bits/stdc++.h>
#define ll long long
#define N 10005

using namespace std;

struct item{
  ll s,e,c;
};


ll dp[32780],BIT[32780];
item arr[N];

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int pos,ll val)
{
    for(;pos<32780;pos+=lowbit(pos))
        BIT[pos]=max(val,BIT[pos]);
}

ll query(int pos)
{
    ll ret=0;
    for(;pos>0;pos-=lowbit(pos))
        ret=max(ret,BIT[pos]);
    return ret;
}

bool cmp(item a,item b)
{
    if(a.e==b.e)
        return a.s<b.s;
    return a.e<b.e;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(BIT,0,sizeof(BIT));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
            cin >> arr[i].s >> arr[i].e >> arr[i].c;
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;++i){
            dp[arr[i].e]=max(dp[arr[i].e],query(arr[i].s)+arr[i].c);
            add(arr[i].e,dp[arr[i].e]);
        }
        ll MAX=0;
        for(int i=0;i<32780;++i)
            MAX=max(dp[i],MAX);
        cout << MAX << endl;
    }
    return 0;
}
