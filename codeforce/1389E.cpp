#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll m,d,w;   cin >> m >> d >> w;
        if(m==1 || d==1){
            cout << "0\n";    continue;
        }
        if((d-1)%w==0){
            cout << min(d,m)*(min(d,m)-1)/2 << endl;
            continue;
        }

        ll ans=0,k=min(d,m),div=w/__gcd(w,d-1);
        ans=(k%div)*(k/div)+(k/div-1)*(k/div)/2*div;
        cout << ans << endl;
    }

    return 0;
}

/*
 *
 */
