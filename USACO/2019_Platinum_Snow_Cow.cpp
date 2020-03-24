#include <bits/stdc++.h>
#define ll long long
#define N 300005

using namespace std;

const int ROOT=1;
int n,q,st[N],ed[N],seg[4*N],lazy[4*N];
map<int,int> mp[N];
vector<int> G[N];


int cnt=0;

void dfs(int now,int par)
{
    st[now]=++cnt;
    for(int next:G[now]){
        if(next==par)   continue;
        dfs(next,now);
    }
    ed[now]=cnt;
}

void init()
{
    cin >> n >> q;

    int u,v;
    for(int i=0;i<n-1;++i){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(ROOT,-1);
}

inline void push(int id,int L,int R)
{
    if(lazy[id]==0) return ;
    lazy[id*2]+=lazy[id];
    lazy[id*2+1]+=lazy[id];
    int mid=(L+R)/2;
    seg[id*2]+=lazy[id]*(mid-L+1);
    seg[id*2+1]+=lazy[id]*(R-mid);
    lazy[id]=0;
}

void add(int id,int L,int R,int l,int r,int val)
{
    if(R<l || L>r)  return ;
    if(l<=L && r>=R){
        lazy[id]+=val;
        seg[id]+=val*(R-L+1);
        return ;
    }
    push(id,L,R);
    int mid=(L+R)/2;
    add(id*2,L,mid,l,r,val);
    add(id*2+1,mid+1,R,l,r,val);
    seg[id]=seg[id*2]+seg[id*2+1];
}

int query(int id,int L,int R,int l,int r)
{
    if(R<l || L>r)  return 0;
    if(l<=L && r>=R)
        return seg[id];
    push(id,L,R);
    int mid=(L+R)/2;
    return query(id*2,L,mid,l,r)+query(id*2+1,mid+1,R,l,r);
}

void solve()
{
    int type,x,c;
    while(q--){
        cin >> type;
        if(type==1){
            cin >> x >> c;
            auto iter=mp[c].upper_bound(st[x]);
            if(iter!=mp[c].begin() && ed[prev(iter)->second]>=ed[x])  continue;   //早就被上色過，是別人的子樹
            while(iter!=mp[c].end() && ed[x]>=ed[iter->second]){
                add(1,1,n,iter->first,ed[iter->second],-1);
                mp[c].erase(iter++);
            }
            mp[c][st[x]]=x;
            add(1,1,n,st[x],ed[x],1);
        }
        else{
            cin >> x;
            cout << query(1,1,n,st[x],ed[x]) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    freopen("snowcow.in","r",stdin);
    freopen("snowcow.out","w",stdout);
    init();
    solve();

    return 0;
}
