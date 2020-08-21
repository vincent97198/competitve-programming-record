

#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=200005;

int n,k;
vector<pair<int,int>> line[N];
set<pair<int,int>> s;


int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;++i){
        int l,r;    cin >> l >> r;
        line[l].push_back({r,i});
    }

    vector<int> ans;
    for(int i=1;i<N;++i){
        while(!s.empty() && s.begin()->first<i ){
            s.erase(s.begin());
        }
        for(pair<int,int> tmp:line[i])
            s.insert(tmp);
        while(s.size()>k){
            ans.push_back(s.rbegin()->second);
            s.erase(prev(s.end()));
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int ANS:ans)
        cout << ANS << " ";
    cout << endl;

    return 0;
}

