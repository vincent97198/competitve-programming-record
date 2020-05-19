#include<bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a>b && d>=c)
            cout << -1 << endl;
        else{
            ll ans=0;
            if(a>b)
                ans=(ll)ceil((a-b)/(double)(c-d))*c+b;
            else
                ans=b;
            cout << ans << endl;
        }
    }

    return 0;
}

