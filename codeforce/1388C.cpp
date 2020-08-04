#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

struct item{
    int all,good,bad;
};

int n,m,p[N],h[N];
bool flag;
vector<int> G[N];

item dfs(int now,int par)
{
    item ret;   ret={p[now],0,0};
    for(int next:G[now]){
        if(next==par)   continue;
        item tmp=dfs(next,now);
        ret.all+=tmp.all,ret.bad+=tmp.bad,ret.good+=tmp.good;
    }
    if(abs(h[now])>ret.all || (ret.all-h[now])%2!=0 || (ret.all-h[now])/2+h[now]<ret.good)
        flag=false;
    ret.good=(ret.all-h[now])/2+h[now];
    ret.bad=ret.all-ret.good;
    
    return ret;
}

int main()
{
    int t;  cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0;i<=n;++i)   G[i].clear();
        for(int i=1;i<=n;++i)   cin >> p[i];
        for(int i=1;i<=n;++i)   cin >> h[i];
        for(int i=0;i<n-1;++i){
            int a,b;    cin >> a >> b;
            G[a].push_back(b);  G[b].push_back(a);
        }

        flag=true;
        dfs(1,-1);
        if(flag && m>=h[1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*
 *
 */
