#include <bits/stdc++.h>
#define int long long

using namespace std;

int val[1000005];

signed main()
{   
    int t;  cin >> t;
    while(t--){
        int x;  cin >> x;
        int sum=1,cnt=1;
        while(sum<x){
            sum+=(++cnt);
        }
        if(sum-1==x)
            cout << cnt+1 << '\n';
        else 
            cout << cnt << '\n';
    }
    
    return 0;
}