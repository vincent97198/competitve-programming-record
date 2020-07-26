#include <bits/stdc++.h>
#define N 2005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    int dp[2*N];  memset(dp,0,sizeof(dp));
    for(int T=1;T<=t;++T){
        int n;  cin >> n;
        int p[2*N],MAX;
        for(int i=0;i<2*n;++i)    cin >> p[i];

        MAX=p[0];
        int cnt=0;
        vector<int> len;
        for(int i=0;i<2*n;++i){
            if(p[i]>MAX){
                MAX=p[i];
                len.push_back(cnt);
                cnt=0;
            }
            ++cnt;
        }
        len.push_back(cnt);
        dp[0]=T;
        for(int lens:len){
            for(int i=n;i>=lens;--i){
                if(dp[i-lens]==T)    dp[i]=T;
            }
        }
        if(dp[n]==T)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*
 *
 */
