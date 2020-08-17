#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

ll n,k,a[N],MIN=1e10,MAX=-1e10;

void init()
{
    cin >> n >> k;
    MIN=1e10,MAX=-1e10;
    for(int i=0;i<n;++i){
        cin >> a[i];
        MAX=max(MAX,a[i]);
        MIN=min(MIN,a[i]);
    }
}

void solve()
{
    if(k&1){
        for(int i=0;i<n;++i)
            cout << MAX-a[i] << " ";
    }
    else{
        for(int i=0;i<n;++i)
            cout << a[i]-MIN << " ";
    }
    cout << endl;
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
