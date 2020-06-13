#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int n;  cin >> n;
    int a[N],b[N],pos[N],d[N];
    for(int i=0;i<n;++i){
        cin >> a[i];
        pos[a[i]]=i;
    }
    for(int i=0;i<n;++i){
        cin >> b[i];
        d[b[i]]=((i-pos[b[i]])+n)%n;
    }
    sort(d+1,d+n+1);
    int now=1,MAX=1;
    for(int i=2;i<=n;++i){
        if(d[i]==d[i-1])
            ++now;
        else
            now=1;
        MAX=max(now,MAX);
    }
    cout << MAX << endl;

    return 0;
}

