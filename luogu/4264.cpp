#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

struct cow{
  ll from,to;
};

int n;
map<int,int> mp;
ll ans=0;
cow arr[N];

void init()
{
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> arr[i].from >> arr[i].to;
        ans+=abs(arr[i].from-arr[i].to);
        if(abs(arr[i].from-arr[i].to)>abs(arr[i].from)){
            if(arr[i].from*arr[i].to>=0){   //同號
                --mp[2*arr[i].from];
                --mp[2*arr[i].to-2*arr[i].from];
            }
            else if(arr[i].from*arr[i].to<=0){      //異號
                --mp[0];
                --mp[2*arr[i].to];
            }
            mp[arr[i].to]+=2;
        }
    }
}

void solve()
{
    ll slope=0,now=-1e9,nowAns=ans;
    for(auto iter=mp.begin();iter!=mp.end();++iter){
        nowAns+=slope*(iter->first-now);
        now=iter->first;
        slope+=iter->second;
        ans=min(nowAns,ans);
    }
    cout << ans << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    init();
    solve();

    return 0;
}

