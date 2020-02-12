#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll n,m,a[N];
        ll tmp[100];
        memset(tmp,0,sizeof(tmp));
        cin >> n >> m;
        for(int i=0;i<m;++i){
            cin >> a[i];
            ++tmp[(ll)log2(a[i])];
        }

        ll num=0;
        ll ans=0;
        bool f=false;
        while(n>0){
            if(n&1){
                if(tmp[num]>0)
                    --tmp[num];
                else{
                    int TMP=num;
                    while(TMP<100 && tmp[TMP]<=0)
                        ++TMP;
                    if(TMP==100){
                        cout << -1 << endl;
                        f=true;
                        break;
                    }
                    ans+=(TMP-num);
                    --tmp[TMP];
                    for(int i=num;i<TMP;++i)
                        ++tmp[i];
                }
            }
            tmp[num+1]+=tmp[num]/2;
            n>>=1;
            ++num;
        }
        if(!f)
            cout << ans << endl;
    }

    return 0;
}

