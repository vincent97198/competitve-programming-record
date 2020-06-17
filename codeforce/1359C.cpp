#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

ll h,c,t;

long double calc(ll n)
{
    return (long double)((h+c)*n+h)/(2*n+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    ll T;  cin >> T;
    while(T--){
        cin >> h >> c >> t;
        if(h+c>=2*t){
            cout << 2 << endl;
            continue;
        }
        long double n=(long double)(t-h)/(h+c-2*t);
        ll nn;
        if(fabs(t-calc(floor(n)))<=fabs(t-calc(ceil(n))))
            nn=floor(n);
        else
            nn=ceil(n);
        if(fabs(t-(h+c)/2.0)<fabs(calc(nn)-t))
            cout << 2 << endl;
        else
            cout << nn*2+1 << endl;
    }

    return 0;
}
/*
 * (h*(n+1)+c*n)/(2n+1)=t
 * (h+c-2t)*n=t-h
 * (h+c)/2
 */
