#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll res=0,now=0,mn=0;
        string s;   cin >> s;   res+=s.size();
        for(ll i=0;i<s.size();++i){
            if(s[i]=='+')
                ++now;
            else
                --now;
            if(now<mn){
                res+=(i+1);
                mn=min(now,mn);
            }
        }
        cout << res << endl;
    }

    return 0;
}

