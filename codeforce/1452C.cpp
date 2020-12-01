#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100005;
int arr[N];

signed main()
{
    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;
        int n=s.size();
        
        int ans=0,l;
        l=0;
        for(int i=0;i<n;++i){
            if(s[i]=='(')
                ++l;
            else if(s[i]==')' && l>0)
                --l,++ans;
        }
        
        l=0;
        for(int i=0;i<n;++i){
            if(s[i]=='[')
                ++l;
            else if(s[i]==']' && l>0)
                --l,++ans;
        }
        cout << ans << '\n';
    }
    
    return 0;
}