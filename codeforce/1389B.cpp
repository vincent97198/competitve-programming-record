#include <bits/stdc++.h>
#define N 100003
#define ll long long

using namespace std;

struct num{
    ll sum,index;
};

bool cmp(num x,num y)
{
    if(x.sum!=y.sum)
        return x.sum>y.sum;
    return x.index>y.index;
}

int main()
{
    int t;  cin >> t;
    while(t--){
        int n,k,z,a[N];  cin >> n >> k >> z;
        num arr[N];
        for(int i=0;i<n;++i)    cin >> a[i];
        for(int i=0;i<n-1;++i)  arr[i].sum=a[i]+a[i+1],arr[i].index=i+1;
        sort(arr,arr+n-1,cmp);

        ll MAX=0,all_sum=0,de=0;
        for(int i=0;i<=k;++i)    all_sum+=a[i];
        MAX=all_sum;

        int rear=k,now_index=0;
        for(ll i=1;i<=z;++i){
            while(arr[now_index].index>=rear)   ++now_index;
            de+=a[rear]+a[rear-1];
            MAX=max(MAX,all_sum-de+i*arr[now_index].sum);
            rear-=2;
            if(rear<=1)  break;
        }

        cout << MAX << endl;
    }

    return 0;
}

/*
 *
 */
