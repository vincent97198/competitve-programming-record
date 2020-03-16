#include <bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;

struct item{
  ll pos,val;
};

bool cmp(item a,item b)
{
    return a.pos<b.pos;
}

bool cmp2(item a,item b)
{
    if(a.val!=b.val)
        return a.val<b.val;

    return a.pos>b.pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int n;
    cin >> n;

    map<ll,ll> mp_L,mp_R;
    ll L,R,W;
    ll sum=0;
    for(int i=0;i<n;++i){
        cin >> L >> R >> W;
        sum+=W;
        mp_L[L]+=W;
        mp_R[R+1]+=W;
    }

    mp_L[1e9+7]+=0;
    mp_R[0]+=0;

    for(auto iter=prev(mp_L.end());iter!=mp_L.begin();--iter)
        prev(iter)->second+=iter->second;
    for(auto iter=mp_R.begin();iter!=prev(mp_R.end());++iter)
        next(iter)->second+=iter->second;

    map<ll,ll> mp_L_val;
    for(auto iter=mp_L.begin();iter!=mp_L.end();++iter)
        mp_L_val[iter->second]=iter->first;

    ll ans=0;
    auto p=mp_L_val.begin();
    for(auto iter=mp_R.begin();iter!=mp_R.end();++iter){
        while(iter->first>p->second)
            ++p;
        if(iter->first<p->second)
            ans=max(ans,sum-iter->second-p->first);
        else
            ans=max(ans,sum-iter->second);
    }
    cout << ans << endl;

    return 0;
}

