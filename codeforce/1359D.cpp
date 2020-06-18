#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int n,ans=0,arr[N];

void check(int val)
{
    int tmp=0;
    for(int i=0;i<n;++i){
        tmp+=arr[i];
        if(arr[i]>val || tmp<0)
            tmp=0;
        ans=max(ans,tmp-val);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    cin >> n;
    for(int i=0;i<n;++i)    cin >> arr[i];
    for(int i=30;i>0;--i){
        check(i);
    }
    cout << ans << endl;

    return 0;
}
