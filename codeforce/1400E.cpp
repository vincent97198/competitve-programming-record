#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5005;
int n,arr[N];

ll calc(int l,int r)
{
    if(l>r) return 0;
    if(l==r)    return arr[l]>0;

    int MIN=1e9,pos;
    for(int i=l;i<=r;++i){
        if(arr[i]<MIN){
            MIN=arr[i];
            pos=i;
        }
    }
    for(int i=l;i<=r;++i)   arr[i]-=MIN;
    return min(r-l+1LL,calc(l,pos-1)+calc(pos+1,r)+MIN);
}

int main()
{
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }

    cout << calc(0,n-1) << endl;
}
/*
 3
 11
 1 2 2 1 2 3 1 5 1 2 1
 5
 2 2 2 2 2
 6
 1 3 3 1 2 3
 */
