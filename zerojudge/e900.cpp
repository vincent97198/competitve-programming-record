#include <bits/stdc++.h>
#define ll long long
#define N 1005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int n;
    while(cin >> n){
        int arr[N],arr2[N],a,b;
        for(int i=0;i<n;++i){
            cin >> a >> b;
            arr[i]=a-b+13;
            arr2[i]=b-a+13;
        }
        bool dp[2][26*N];
        int ans[2][26*N];
        memset(dp,0,sizeof(dp));
        memset(ans,0x7f,sizeof(ans));
        dp[0][0]=true;
        ans[0][0]=0;
        for(int i=0;i<n;++i){
            memset(dp[(i+1)&1],0,sizeof(dp[(i+1)&1]));
            memset(ans[(i+1)&1],0x7f,sizeof(ans[(i+1)&1]));
            for(int j=26*N-1;j>=arr[i];--j){
                if(dp[i&1][j-arr[i]]){
                    dp[(i+1)&1][j]=true;
                    ans[(i+1)&1][j]=min(ans[(i+1)&1][j],ans[i&1][j-arr[i]]);
                }
            }
            for(int j=26*N-1;j>=arr2[i];--j){
                if(dp[i&1][j-arr2[i]]){
                    dp[(i+1)&1][j]=true;
                    ans[(i+1)&1][j]=min(ans[i&1][j-arr2[i]]+1,ans[(i+1)&1][j]);
                }
            }
        }
        for(int i=0;i<=13*n;++i){
            if(dp[n&1][13*n-i] && dp[n&1][13*n+i]){
                cout << min(ans[n&1][13*n+i],ans[n&1][13*n-i]);
                break;
            }
            else if(dp[n&1][13*n-i] || dp[n&1][13*n+i]){
                cout << max(ans[n&1][13*n+i],ans[n&1][13*n-i]);
                break;
            }
        }
        cout << endl;
    }

    return 0;
}
