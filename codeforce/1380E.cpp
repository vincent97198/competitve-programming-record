#include <bits/stdc++.h>
#define N 200005
#define ll long long

using namespace std;

int n,m,ans;
set<int> tower[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0;i<n;++i){
        int tmp;    cin >> tmp;
        tower[tmp].insert(i+1);
    }

    ans=n;
    for(int i=1;i<=m;++i){
        for(auto iter=tower[i].begin();iter!=prev(tower[i].end());++iter){
            if(*iter==*(next(iter))-1)
                --ans;
        }
    }

    for(int i=0;i<m-1;++i){
        cout << ans-1 << '\n';
        int a,b;    cin >> a >> b;

        if(tower[a].size()<tower[b].size())
            swap(tower[a],tower[b]);

        for(auto iter=tower[b].begin();iter!=tower[b].end();++iter){
            ans-=tower[a].count(*iter-1);
            ans-=tower[a].count(*iter+1);
        }
        for(auto iter=tower[b].begin();iter!=tower[b].end();++iter) tower[a].insert(*iter);
        tower[b].clear();
    }
    cout << ans-1 << endl;

    return 0;
}
