#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a,b,n,m;
        cin >> a >> b >> n >> m;
        if(a+b>=n+m && min(a,b)>=m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*
 * last
 *  v->1 c->2
 *  c->2
 */
