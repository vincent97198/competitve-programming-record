#include <bits/stdc++.h>
#define ll long long
#define N 1000005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t,p[N],s[N],n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<n;++i)
            cin >> p[i];
        for(int i=0;i<n;++i)
            cin >> s[i];

        int tmp=INT_MAX;
        for(int i=n-1;i>=0;--i){
            tmp=min(tmp,s[i]);
            tmp=max(tmp,p[i]);
            s[i]=tmp;
        }

        int ans=0;
        tmp=INT_MAX;
        for(int i=0;i<n;++i){
            tmp=max(tmp,p[i]);
            tmp=min(tmp,s[i]);
            s[i]=tmp;
            ans+=s[i]-p[i];
        }
        cout << ans << endl;
    }

    return 0;
}

