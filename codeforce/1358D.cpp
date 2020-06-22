#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    ll n,x;    cin >> n >> x;
    ll arr[2*N];
    for(int i=0;i<n;++i){
        cin >> arr[i];
        arr[n+i]=arr[i];
    }
    ll nowANS=0,days=0,ans=0;
    queue<ll> q;
    for(int i=0;i<2*n;++i){
        nowANS+=arr[i]*(arr[i]+1)/2;
        days+=arr[i];
        q.push(i);
        while(days>x){
            days-=arr[q.front()];
            nowANS-=arr[q.front()]*(arr[q.front()]+1)/2;
            q.pop();
        }
        if(q.empty()){
            ans=max(ans,(2*arr[i]-x+1)*x/2);
            continue;
        }
        ll tmp=nowANS;
        if(q.front()>0) tmp+=(2*arr[q.front()-1]-(x-days)+1)*(x-days)/2;
        ans=max(ans,tmp);
    }
    cout << ans << endl;

    return 0;
}
