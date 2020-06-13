#include <bits/stdc++.h>
#define ll long long
#define N 5005

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll a,b; cin >> a >> b;
        if(min(a,b)*2<max(a,b)){
            cout << min(a,b) << endl;
        }
        else{
            cout << (a+b)/3 << endl;
        }
    }
    return 0;
}
/*
 * 2x+y=a
 * x+2y=b;
 * x+y
 * y=a-2x
 * x+2a-4x=b
 * 3x=2a-b
 */
