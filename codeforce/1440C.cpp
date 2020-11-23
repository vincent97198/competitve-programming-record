#include <bits/stdc++.h>
#define int long long

using namespace std;

struct item{
    int x1,y1,x2,y2,x3,y3;
};

int MAP[105][105];
vector<item> v;

void calc(int X1,int Y1,int X2,int Y2,int X3,int Y3,int X4,int Y4)
{
    int cnt;
    
    do{
        cnt=MAP[X1][Y1]+MAP[X2][Y2]+MAP[X3][Y3]+MAP[X4][Y4];
        if(cnt==1){
            if(MAP[X1][Y1]==1){
                v.push_back(item{X2,Y2,X3,Y3,X1,Y1});
                MAP[X2][Y2]^=1; MAP[X3][Y3]^=1; MAP[X1][Y1]^=1;
            }
            else if(MAP[X2][Y2]==1){
                v.push_back(item{X2,Y2,X3,Y3,X4,Y4});
                MAP[X2][Y2]^=1; MAP[X3][Y3]^=1; MAP[X4][Y4]^=1;
            }
            else if(MAP[X3][Y3]==1){
                v.push_back(item{X3,Y3,X1,Y1,X4,Y4});
                MAP[X1][Y1]^=1; MAP[X3][Y3]^=1; MAP[X4][Y4]^=1;
            }
            else if(MAP[X4][Y4]==1){
                v.push_back(item{X3,Y3,X1,Y1,X4,Y4});
                MAP[X1][Y1]^=1; MAP[X3][Y3]^=1; MAP[X4][Y4]^=1;
            }
        }
        else if(cnt==2){
            int reX,reY;
            if(MAP[X1][Y1]==1){
                v.push_back(item{X2,Y2,X3,Y3,X4,Y4});
                MAP[X2][Y2]^=1; MAP[X3][Y3]^=1; MAP[X4][Y4]^=1;
            }
            else if(MAP[X2][Y2]==1){
                v.push_back(item{X1,Y1,X3,Y3,X4,Y4});
                MAP[X1][Y1]^=1; MAP[X3][Y3]^=1; MAP[X4][Y4]^=1;
            }
            else if(MAP[X3][Y3]==1){
                v.push_back(item{X2,Y2,X1,Y1,X4,Y4});
                MAP[X1][Y1]^=1; MAP[X2][Y2]^=1; MAP[X4][Y4]^=1;
            }
        }
        else if(cnt==3){
            if(MAP[X2][Y2]==0)
                swap(X1,X2),swap(Y1,Y2);
            if(MAP[X3][Y3]==0)
                swap(X1,X3),swap(Y1,Y3);
            if(MAP[X4][Y4]==0)
                swap(X1,X4),swap(Y1,Y4);
            v.push_back(item{X4,Y4,X2,Y2,X3,Y3});
            MAP[X1][Y1]=MAP[X2][Y2]=MAP[X3][Y3]=MAP[X4][Y4]=0;
        }
        else if(cnt==4){
            v.push_back(item{X1,Y1,X2,Y2,X3,Y3});
            MAP[X1][Y1]^=1; MAP[X2][Y2]^=1; MAP[X3][Y3]^=1;
        }
        
    }while(cnt!=0);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        v.clear();
        int n,m;    cin >> n >> m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin >> MAP[i][j];
        
        if((n&1)&(m&1)){
            for(int i=1;i+1<=n;i+=2){
                if(MAP[i][m] && MAP[i+1][m]){
                    MAP[i][m]=MAP[i+1][m]=0;
                    MAP[i][m-1]^=1;
                    v.push_back(item{i,m,i+1,m,i,m-1});
                }
                else if(MAP[i][m] || MAP[i+1][m]){
                    if(MAP[i][m])
                        v.push_back(item{i,m,i,m-1,i+1,m-1});
                    else
                        v.push_back(item{i+1,m,i,m-1,i+1,m-1});
                    MAP[i][m]=MAP[i+1][m]=0;
                    MAP[i][m-1]^=1;
                    MAP[i+1][m-1]^=1;
                }
            }
            
            for(int j=1;j+1<=m;j+=2){
                if(MAP[n][j] && MAP[n][j+1]){
                    MAP[n][j]=MAP[n][j+1]=0;
                    MAP[n-1][j]^=1;
                    v.push_back(item{n,j,n,j+1,n-1,j});
                }
                else if(MAP[n][j] || MAP[n][j+1]){
                    if(MAP[n][j])
                        v.push_back(item{n,j,n-1,j,n-1,j+1});
                    else
                        v.push_back(item{n,j+1,n-1,j,n-1,j+1});
                    MAP[n][j]=MAP[n][j+1]=0;
                    MAP[n-1][j]^=1;
                    MAP[n-1][j+1]^=1;
                }
            }
            
            calc(n,m,n-1,m,n,m-1,n-1,m-1);
        }
        else if(n&1){
            for(int j=1;j+1<=m;j+=2){
                if(MAP[n][j] && MAP[n][j+1]){
                    MAP[n][j]=MAP[n][j+1]=0;
                    MAP[n-1][j]^=1;
                    v.push_back(item{n,j,n,j+1,n-1,j});
                }
                else if(MAP[n][j] || MAP[n][j+1]){
                    if(MAP[n][j])
                        v.push_back(item{n,j,n-1,j,n-1,j+1});
                    else
                        v.push_back(item{n,j+1,n-1,j,n-1,j+1});
                    MAP[n][j]=MAP[n][j+1]=0;
                    MAP[n-1][j]^=1;
                    MAP[n-1][j+1]^=1;
                }
            }
        }
        else if(m&1){
            for(int i=1;i+1<=n;i+=2){
                if(MAP[i][m] && MAP[i+1][m]){
                    MAP[i][m]=MAP[i+1][m]=0;
                    MAP[i][m-1]^=1;
                    v.push_back(item{i,m,i+1,m,i,m-1});
                }
                else if(MAP[i][m] || MAP[i+1][m]){
                    if(MAP[i][m])
                        v.push_back(item{i,m,i,m-1,i+1,m-1});
                    else
                        v.push_back(item{i+1,m,i,m-1,i+1,m-1});
                    MAP[i][m]=MAP[i+1][m]=0;
                    MAP[i][m-1]^=1;
                    MAP[i+1][m-1]^=1;
                }
            }
        }
        for(int i=1;i+1<=((n>>1)<<1);i+=2){
            for(int j=1;j+1<=((m>>1)<<1);j+=2){
                calc(i,j,i+1,j,i,j+1,i+1,j+1);
            }
        }
        
        cout << v.size() << '\n';
        for(int i=0;i<v.size();++i){
            cout << v[i].x1 << " " << v[i].y1 << " " << v[i].x2 << " " << v[i].y2 << " " << v[i].x3 << " " << v[i].y3 << '\n';
        }
    }

    
    return 0;
}