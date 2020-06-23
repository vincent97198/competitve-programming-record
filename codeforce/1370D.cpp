#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int n,k,arr[N];

bool check(int x,bool cnt)
{
    int ans=0;
    for(int i=0;i<n;++i){
        if(!cnt){
            ++ans;
            cnt^=true;
        }
        else{
            if(arr[i]<=x){
                ++ans;
                cnt^=true;
            }
        }
    }
    return ans>=k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    cin >> n >> k;
    for(int i=0;i<n;++i)    cin >> arr[i];

    int l=0,r=1e9,mid;
    while(r>l){
        mid=(l+r)/2;
        if(check(mid,true) || check(mid,false))
            r=mid;
        else
            l=mid+1;
    }
    cout << l << endl;

    return 0;
}
