#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n;  cin >> n;
    int arr[30];    memset(arr,0,sizeof(arr));
    for(int i=0;i<n;++i){
        int tmp,cnt=0;    cin >> tmp;
        while(tmp>0){
            arr[cnt++]+=tmp&1;
            tmp>>=1;
        }
    }
    ll ans=0;
    for(int i=0;i<n;++i){
        ll tmp=0;
        for(int j=29;j>=0;--j){
            tmp=(tmp<<1)+(arr[j]>0);
            --arr[j];
        }
        ans+=tmp*tmp;
    }
    cout << ans << endl;

    return 0;
}

/*
 * 0010
 * 0110
 * 1001
 * 1
 * 1
 * 111
 *
 * 10101010101010101010
 * 01010101010101010101
 */
