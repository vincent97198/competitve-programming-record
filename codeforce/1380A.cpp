#include <bits/stdc++.h>
#define N 5005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n,p[N];  cin >> n;
        pair<int,int> mn[N];
        for(int i=0;i<n;++i)    cin >> p[i];
        mn[n-1].first=p[n-1],mn[n-1].second=n-1;
        for(int i=n-2;i>=0;--i){
            if(mn[i+1].first<p[i])
                mn[i]=mn[i+1];
            else
                mn[i].first=p[i],mn[i].second=i;
        }
        int MN=p[0],pos=0;
        bool flag=false;
        for(int i=1;i<n-1;++i){
            if(p[i]>MN && p[i]>mn[i+1].first){
                cout << "YES" << endl;
                cout << pos+1 << " " << i+1 << " " << mn[i+1].second+1 << endl;
                flag=true;
            }
            if(MN>p[i])
                MN=p[i],pos=i;
            if(flag)
                break;
        }
        if(!flag)
            cout << "NO" << endl;
    }

    return 0;
}
