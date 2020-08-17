#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

int n,a[N];

void init()
{
    cin >> n;
    int MAX=0,MIN=1e9;
    for(int i=0;i<n;++i){
        cin >> a[i];
        MAX=max(MAX,a[i]);
        MIN=min(MIN,a[i]);
    }
    if(MAX!=MIN)
        cout << 1 << endl;
    else
        cout << n << endl;
}

void solve()
{

}

int main()
{
    int t;  cin >> t;
    while(t--){
        init();
        solve();
    }

    return 0;
}

/*
 * 9 5
 * 1
 * 8 5 2
 */
