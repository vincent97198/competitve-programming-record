#include <bits/stdc++.h>
#define ll long long
#define N 205

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    int vis[N],p=0;
    memset(vis,0,sizeof(vis));
    while(t--){
        ++p;
        int n,b[N];
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> b[i];
            vis[b[i]]=p;
        }
        int index;
        bool f=false;
        vector<int> ans;
        for(int i=0;i<n;++i){
            index=-1;
            for(int j=b[i]+1;j<=2*n;++j){
                if(vis[j]!=p){
                    index=j;
                    break;
                }
            }
            if(index==-1){
                f=true;
                break;
            }
            vis[index]=p;
            ans.push_back(b[i]);   ans.push_back(index);
        }
        if(!f){
            for(int i=0;i<ans.size();++i)
                cout << ans[i] << " ";
        }
        else
            cout << -1;
        cout << endl;
    }

    return 0;
}

