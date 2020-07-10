#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int n,p,a[N];

int check(int x)
{
    int now=0,cnt=0,mx=0;
    while(now!=n && a[now]<=x){
        ++now,++cnt;
    }
    mx=max(mx,cnt);
    while(now!=n && cnt!=0){
        --cnt,++x;
        while(now!=n && a[now]<=x){
            ++now,++cnt;
        }
        mx=max(mx,cnt);
    }
    if(now!=n)
        return 0;
    return mx;
}

int main()
{
    cin >> n >> p;
    for(int i=0;i<n;++i)    cin >> a[i];

    sort(a,a+n);

    int l=0,r=1e9;

    while(r>l){
        int m=(l+r)/2;
        if(check(m)==0)
            l=m+1;
        else
            r=m;
    }

    int L=l;

    l=0,r=1e9;
    while(r>l){
        int m=(l+r+1)/2;
        if(check(m)<p)
            l=m;
        else
            r=m-1;
    }

    cout << l-L+1 << endl;
    for(int i=L;i<=l;++i)
        cout << i << " ";

    return 0;
}

