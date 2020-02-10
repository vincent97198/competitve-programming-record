#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

struct pos{
  int x,y;
};

int n,sum[N],len;

void init()
{
    cin >> n >> len;
    sum[0]=0;
    char f;
    for(int i=1;i<=n;++i){
        cin >> f;
        if(f=='1')
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
}

bool calc(pos a,pos b,int now,bool flag)
{
    double fst=(sum[now]-b.y)/(double)(now-b.x);
    double snd=(b.y-a.y)/(double)(b.x-a.x);

    if(flag)
        return snd>=fst;
    else
        return fst>=snd;
}

void solve()
{
    deque<pos> dq;

    int l=0,r=len;
    double ans=(sum[r]-sum[l])/(double)(r-l);
    dq.push_back(pos{0,0});
    for(int i=len+1;i<=n;++i){
        while(dq.size()>=2 && calc(dq[dq.size()-2],dq.back(),i-len,true))
            dq.pop_back();

        dq.push_back(pos{i-len,sum[i-len]});

        while(dq.size()>=2 && calc(dq.front(),dq[1],i,false))
            dq.pop_front();

        double tmp=(sum[i]-dq.front().y)/(double)(i-dq.front().x);
        if(tmp>ans || (tmp==ans && (i-dq.front().x)<(r-l) )){
            l=dq.front().x;
            ans=tmp;
            r=i;
        }
    }
    cout << l+1 << " " << r << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        init();
        solve();
    }

    return 0;
}

