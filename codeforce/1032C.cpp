#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int n,a[N],dp[N][6];

int main()
{
    cin >> n;
    for(int i=1;i<=n;++i)
        cin >> a[i];
    a[0]=a[1];

    for(int i=1;i<=n;++i){
        for(int j=1;j<=5;++j){
            if(dp[i-1][j]==0 && i-1!=0)   continue;
            for(int k=1;k<=5;++k){
                if(a[i]>a[i-1] && k>j)
                    dp[i][k]=j;
                else if(a[i]<a[i-1] && k<j)
                    dp[i][k]=j;
                else if(a[i]==a[i-1] && k!=j)
                    dp[i][k]=j;
            }
        }
    }

    int ans[N];
    int cnt=0;
    for(int i=1;i<=5;++i){
        if(dp[n][i]!=0)
            cnt=i;
    }
    if(cnt==0){
        cout << "-1\n";
        return 0;
    }
    for(int i=n;i>=1;--i){
        ans[i]=cnt;
        cnt=dp[i][cnt];
    }
    for(int i=1;i<=n;++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}

/*
 * 1 1 4 2 2
 */
