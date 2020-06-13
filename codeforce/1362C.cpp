#include <bits/stdc++.h>
#define ll long long
#define N 1030

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        ll n;   cin >> n;
        ll ans=0,power=2;
        while(n>0){
            if(n&1)
                ans+=power-1;
            power<<=1,n>>=1;
        }
        cout << ans << endl;
    }

    return 0;
}
/*
 * 101 => 8
 * 111 => 7+3+1
 * 1011 => 1+3+15
 */

