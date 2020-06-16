#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n,m,k;  cin >> n >> m >> k;
        int winner=min(n/k,m);
        m-=n/k;
        if(m>0)
            cout << winner-ceil(m/(k-1.0)) << endl;
        else
            cout << winner << endl;
    }

    return 0;
}

