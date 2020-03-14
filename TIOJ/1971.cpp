#include <bits/stdc++.h>
#define N 25
#define ll long long

using namespace std;

ll arr[N],vis[1<<21];
bool SG[100000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    ll m,n;
    cin >> m >> n;
    for(int i=0;i<n;++i)
        cin >> arr[i];

    sort(arr,arr+n);
    //memset(SG,0,sizeof(SG));
    if(m<=100000000){
        ll ans=0;
        for(ll i=0;i<=m;++i){
            if(!SG[i]){
                for(ll j=0;j<n && arr[j]+i<=m;++j)
                    SG[i+arr[j]]=true;
            }
            else
                ++ans;
        }
        cout << ans << endl;
    }
    else{
        ll status=0,now,MOD=1<<arr[n-1],point;
        for(now=0;now<arr[n-1];++now){
            status=(status<<1)|SG[now];
            if(!SG[now]){
                for(ll i=0;i<n;++i)
                    SG[now+arr[i]]=true;
            }
        }

        while(true){
            status=((status<<1)|SG[now])%MOD;

            if(vis[status]!=0)
                break;
            if(!SG[now]){
                for(int i=0;i<n;++i)
                    SG[arr[i]+now]=true;
            }
            vis[status]=now++;
        }
        ll ans=0,route=0;
        for(int i=0;i<vis[status];++i){
            if(SG[i])
                ++ans;
        }
        for(int i=vis[status];i<now;++i){
            if(SG[i])
                ++route;
        }
        ans+=route*((m-vis[status]+1)/(now-vis[status]));
        for(int i=0;i<(m-vis[status]+1)%(now-vis[status]);++i)
            if(SG[i+vis[status]])
                ++ans;
        cout << ans << endl;
    }

    return 0;
}

