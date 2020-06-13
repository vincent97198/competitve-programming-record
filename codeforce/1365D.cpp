#include <bits/stdc++.h>
#define ll long long
#define N 51

using namespace std;

pair<int,int> d[4]={{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n,m;    cin >> n >> m;
        char mp[N][N];
        vector<pair<int,int>> b,g;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> mp[i][j];
                if(mp[i][j]=='B')
                    b.emplace_back(i,j);
                else if(mp[i][j]=='G')
                    g.emplace_back(i,j);
            }
        }
        for(pair<int,int> pr:b){
            for(auto & i : d){
                if(pr.first+i.first>=n || pr.first+i.first<0 || pr.second+i.second>=m || pr.second+i.second<0 || mp[pr.first+i.first][pr.second+i.second]!='.')
                    continue;
                mp[pr.first+i.first][pr.second+i.second]='#';
            }
        }
/*
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)
                cout << mp[i][j] << " ";
            cout << endl;
        }
*/
        bool vis[N][N]; memset(vis,0,sizeof(vis));
        queue<pair<int,int>> q;
        if(mp[n-1][m-1]!='#'){
            q.push({n-1,m-1});
            vis[n-1][m-1]=true;
        }

        while(!q.empty()){
            auto pr=q.front(); q.pop();
            for(auto & i : d){
                if(pr.first+i.first>=n || pr.first+i.first<0 || pr.second+i.second>=m || pr.second+i.second<0 || vis[pr.first+i.first][pr.second+i.second] || mp[pr.first+i.first][pr.second+i.second]=='#')
                    continue;
                vis[pr.first+i.first][pr.second+i.second]=true;
                q.push({pr.first+i.first,pr.second+i.second});
            }
        }
        bool flag=false;
        for(auto &tmp:g){
            if(!vis[tmp.first][tmp.second]){
                cout << "No" << endl;
                flag=true;
                break;
            }
        }
        if(flag)    continue;
        for(auto &tmp:b){
            if(vis[tmp.first][tmp.second]){
                cout << "No" << endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            cout << "Yes" << endl;
    }

    return 0;
}

