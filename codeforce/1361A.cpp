#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

int n,m;
vector<int> G[N];
pair<int,int> arr[N];

bool check()
{
    int num[N]; memset(num,-1,sizeof(num));
    for(int i=0;i<n;++i){
        set<int> tmp;
        num[arr[i].second]=arr[i].first;
        for(int v:G[arr[i].second]){
            if(num[v]==arr[i].first)
                return false;
            if(num[v]!=-1 && num[v]<arr[i].first)
                tmp.insert(num[v]);
        }
        if(tmp.size()!=arr[i].first-1)
            return false;
    }
    return true;
}

void init()
{
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int u,v;    cin >> u >> v;
        G[u].emplace_back(v),G[v].emplace_back(u);
    }
    for(int i=0;i<n;++i){
        cin >> arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr,arr+n);
}

void solve()
{
    if(check()){
        for(int i=0;i<n;++i)    cout << arr[i].second << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    init();
    solve();

    return 0;
}
