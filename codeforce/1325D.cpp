#include <bits/stdc++.h>
#define N 25
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    ll u,sum;
    cin >> u >> sum;

    if(u==sum && u==0)
        cout << 0 << endl;
    else if(u==sum)
        cout << "1\n" << " " << u << endl;
    else if((u&1)^(sum&1)||u>sum)
        cout << -1 << endl;
    else{
        ll tmp=(sum-u)/2;
        if(((tmp+u)^tmp)==u)
            cout << "2\n" << tmp+u << " " << tmp << endl;
        else
            cout << "3\n" << tmp << " " << tmp << " " << u << endl;
    }

    return 0;
}

/*
   a+b=a^b+2*(a&b);
   a&b=(sum-u)/2;
*/

