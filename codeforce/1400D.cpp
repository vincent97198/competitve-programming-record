#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll C(ll x)
{
    return x*(x-1)/2;
}

ll calc(ll x)
{
    return x*(x-1)*(x-2)*(x-3)/(1*2*3*4);
}

const int N=3005;
vector<int> num[N];

int main()
{
   int t;   cin >> t;
   while(t--){
       int n,arr[N];   cin >> n;
       for(int i=0;i<n;++i) cin >> arr[i];

       int cnt[N];
       for(int i=0;i<=n;++i)    cnt[i]=0;
       ll ans=0,sum;
       for(int i=0;i<n;++i){
           sum=0;
           for(int j=i+1;j<n;++j){
               if(arr[i]==arr[j])
                   ans+=sum;
               sum+=cnt[arr[j]];
           }
           ++cnt[arr[i]];
       }
       cout << ans << endl;
   }
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
