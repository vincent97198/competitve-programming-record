#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n,x,a[N];    cin >> n >> x;
        map<int,int> mp;
        for(int i=0;i<n;++i){
            cin >> a[i];
            ++mp[ceil((double)x/a[i])];
        }
        int ans=0;
        for(auto iter=mp.begin();iter!=mp.end();++iter){
            ans+=(iter->second/iter->first);
            if(next(iter)!=mp.end())
                next(iter)->second+=(iter->second%iter->first);
        }
        cout << ans << endl;
    }
    return 0;
}
