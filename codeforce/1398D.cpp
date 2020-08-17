#include <bits/stdc++.h>
#define ll long long
#define N 205

using namespace std;

ll color[3][N];
ll dp[N][N][N];

int main()
{
    int R,G,B;  cin >> R >> G >> B;
    for(int i=1;i<=R;++i)    cin >> color[0][i];
    for(int i=1;i<=G;++i)    cin >> color[1][i];
    for(int i=1;i<=B;++i)    cin >> color[2][i];
    sort(color[0]+1,color[0]+R+1,greater<ll>());    sort(color[1]+1,color[1]+G+1,greater<ll>());    sort(color[2]+1,color[2]+B+1,greater<ll>());

    for(int i=0;i<=R;++i){
        for(int j=0;j<=G;++j){
            for(int k=0;k<=B;++k){
                if(i>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
                if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]);
                dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+color[0][i+1]*color[1][j+1]);
                dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+color[2][k+1]*color[1][j+1]);
                dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+color[0][i+1]*color[2][k+1]);
            }
        }
    }
    cout << dp[R][G][B] << endl;

    return 0;
}

/*
 * 9 5
 * 1
 * 8 5 2
 */
