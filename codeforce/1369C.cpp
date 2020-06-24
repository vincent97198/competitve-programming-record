#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n,k;    cin >> n >> k;
        int arr[N],num[N];
        for(int i=0;i<n;++i)    cin >> arr[i];
        for(int i=0;i<k;++i){
            cin >> num[i];
            --num[i];
        }

        sort(arr,arr+n);
        reverse(arr,arr+n);
        sort(num,num+k);

        ll ans=0,cnt=k-1;
        for(int i=0;i<k;++i){
            if(num[i]==0)  ans+=arr[i];
            ans+=arr[i];
        }
        for(int i=0;i<k;++i){
            if(num[i]!=0){
                cnt+=num[i];
                ans+=arr[cnt];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
