#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int n,m,k,arr[N],dis[N];
vector<int> G[N],invG[N];

struct cmp{
    bool operator()(int a,int b){
        return dis[a]>dis[b];
    }
};

void init()
{
    cin >> n >> m;
    int u,v;
    for(int i=0;i<m;++i){
        cin >> u >> v;
        G[u].push_back(v);
        invG[v].push_back(u);
    }
    cin >> k;
    for(int i=0;i<k;++i)
        cin >> arr[i];
    memset(dis,0x7f,sizeof(dis));
}

void dijkstra()
{
    priority_queue<int,vector<int>,cmp> pq;
    pq.push(arr[k-1]);
    dis[arr[k-1]]=0;
    while(!pq.empty()){
        int now=pq.top();   pq.pop();
        for(int next:invG[now]){
            if(dis[next]>dis[now]+1){
                dis[next]=dis[now]+1;
                pq.push(next);
            }
        }
    }
}

void solve()
{
    dijkstra();

    int MIN=0,MAX=0;
    vector<int> MINnext;
    for(int i=0;i<k-1;++i){
        int now=arr[i];
        MINnext.clear();
        if(dis[arr[i+1]]==dis[now]-1){
            for(int next:G[now]){
                if(next!=arr[i+1] && dis[next]==dis[now]-1){
                    ++MAX;
                    break;
                }
            }
        }
        else{
            ++MIN;
            ++MAX;
        }
    }
    cout << MIN << " " << MAX << endl;
}

int main()
{
    init();
    solve();

    return 0;
}
