#include <bits/stdc++.h>
#define N 300005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n,arr[N];  cin >> n;
        for(int i=0;i<n;++i)    cin >> arr[i];
        sort(arr,arr+n,greater<int>());
        //for(int i=0;i<n;++i)    cout << arr[i] << " ";
        int dp[N];
        for(int i=0;i<=n;++i)   dp[i]=0;
        for(int i=0;i<n;++i){
            if(i>0) dp[i]=max(dp[i],dp[i-1]);
            if(i+arr[i]<=n)
                dp[i+arr[i]]=max(dp[i+arr[i]],dp[i]+1);
        }
        cout << max(dp[n],dp[n-1]) << endl;
    }

    return 0;
}

/*
 *
 */
