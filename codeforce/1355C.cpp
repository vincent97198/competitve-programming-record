#include <bits/stdc++.h>
#define N 500005
#define ll long long

using namespace std;

int main()
{
    int A,B,C,D;    cin >> A >> B >> C >> D;
    ll arr[2*N]; memset(arr,0,sizeof(arr));
    for(int i=A;i<=B;++i){
        ++arr[i+B];
        --arr[i+C+1];
    }
    for(int i=1;i<2*N;++i)    arr[i]+=arr[i-1];
    for(int i=1;i<2*N;++i)    arr[i]+=arr[i-1];
    ll ans=0;
    for(int i=C;i<=D;++i)   ans+=arr[2*N-1]-arr[i];
    cout << ans << endl;

    return 0;
}

/*
 *
 */
