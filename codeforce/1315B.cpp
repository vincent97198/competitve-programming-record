#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    ll t,a,b,p,dp[N];
    cin >> t;
    while(t--){
        string s;
        bool f=false;
        cin >> a >> b >> p >> s;
        dp[s.size()-1]=0;   dp[s.size()-2]=(s[s.size()-2]=='A'?a:b);
        for(int i=s.size()-3;i>=0;--i){
            if(s[i]==s[i+1])
                dp[i]=dp[i+1];
            else
                dp[i]=dp[i+1]+(s[i]=='A'?a:b);
        }
        for(int i=0;i<s.size();++i){
            if(dp[i]<=p){
                cout << i+1 << endl;
                f=true;
                break;
            }
        }
        if(!f)
            cout << 0 << endl;
    }

    return 0;
}

