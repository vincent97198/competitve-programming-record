#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int t;  cin >> t;
    while(t--){
        int x,y;    cin >> x >> y;
        if(y==0){
            cout << x << " 0\n";
            continue;
        }
        cout << x-1 << " " << y << '\n';
    }
    
    return 0;
}