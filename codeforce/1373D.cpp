#include <bits/stdc++.h>
#define N 200005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        ll n,a[N];  cin >> n;
        for(int i=0;i<n;++i)    cin >> a[i];

        ll pre_mn_now=0,pre_mn_now2=0,now=0,now2=0,mx=0,sum=0;
        for(int i=0,j=1;i<n || j<n;i+=2,j+=2){
            if(i+1<n)
                now+=a[i+1]-a[i];
            if(j+1<n)
                now2+=a[j]-a[j+1];
            mx=max(mx,max(now-pre_mn_now,now2-pre_mn_now2));
            pre_mn_now2=min(pre_mn_now2,now2);
            pre_mn_now=min(pre_mn_now,now);
            sum+=a[i];
        }
        cout << sum+mx << endl;
    }

    return 0;
}

