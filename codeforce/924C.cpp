#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int n,m[N];

int main()
{
    cin >> n;
    int tmp[N];
    for(int i=0;i<n;++i){
        cin >> m[i];
        tmp[i]=m[i];
        if(i>0) tmp[i]=max(tmp[i-1],tmp[i]);
    }
    for(int i=n-2;i>=0;--i)
        tmp[i]=max(tmp[i],tmp[i+1]-1);
    ll ans=0;
    for(int i=0;i<n;++i){
        ans+=(tmp[i]-m[i]);
    }
    cout << ans << endl;

    return 0;
}

/*
 * 9 5
 * 1
 * 8 5 2
 */
