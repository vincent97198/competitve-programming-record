#include <bits/stdc++.h>
#define ll long long
#define N 55

using namespace std;

int m,arr[N];
map<char,int> mp;
string s;

void init()
{
    s="";   s.clear();
    mp.clear();
    cin >> s >> m;
    for(char ch:s)     ++mp[ch];
    for(int i=0;i<m;++i)    cin >> arr[i];
}

void solve()
{
    char ans[N];
    int cnt=0;
    auto iter=prev(mp.end());
    while(cnt<m){
        vector<int> pos;
        for(int i=0;i<m;++i){
            if(arr[i]==0)
                pos.emplace_back(i);
        }
        for(int i=0;i<m;++i){
            if(arr[i]==0) arr[i]=INT_MAX;
            for(int POS:pos)
                arr[i]-=abs(POS-i);
        }
        while(iter->second<pos.size())     --iter;
        for(int POS:pos)
            ans[POS]=iter->first;
        --iter;
        cnt+=pos.size();
    }

    for(int i=0;i<m;++i)
        cout << ans[i];
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int T;  cin >> T;
    while(T--){
        init();
        solve();
    }

    return 0;
}
