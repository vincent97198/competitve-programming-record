#include <bits/stdc++.h>
#define ll long long
#define N 105

using namespace std;

struct item{
  int t,l,r;
};

item arr[N];

bool cmp(item a,item b)
{
    return a.t<b.t;
}


int main()
{
    int q;
    cin >> q;
    while(q--){
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;++i)
            cin >> arr[i].t >> arr[i].l >> arr[i].r;
        sort(arr,arr+n,cmp);

        int now_t=0,MAX=m,MIN=m;
        bool flag=true;
        for(int i=0;i<n;++i){
            if(MAX+arr[i].t-now_t<arr[i].l || MIN-arr[i].t+now_t>arr[i].r)
                flag=false;
            MIN=max(arr[i].l,MIN-arr[i].t+now_t);
            MAX=min(arr[i].r,MAX+arr[i].t-now_t);
            now_t=arr[i].t;
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
