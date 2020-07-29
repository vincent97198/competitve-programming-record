#include <bits/stdc++.h>
#define N 55
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll l,r,x,y; cin >> l >> r;
        if(l&1)
            x=l+1;
        else
            x=l;
        y=x/2*3;
        if(l<=2*y && 2*y<=r)
            cout << x << " " << y << endl;
        else{
            if(r&1)
                y=r-1;
            else
                y=r;
            x=y/2;
            if(l<=x)
                cout << x << " " << y << endl;
            else
                cout << "-1 -1\n";
        }
    }

    return 0;
}

/*
 *
 */
