#include <bits/stdc++.h>
#define N 500005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll x,y,a,b;    cin >> x >> y >> a >> b;
        if(b>2*a)
            cout << (x+y)*a << endl;
        else
            cout << b*min(x,y)+(max(x,y)-min(x,y))*a << endl;
    }

    return 0;
}

/*
 *
 */
