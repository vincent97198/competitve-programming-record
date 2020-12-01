#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100005;
int arr[N];

signed main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int MAX=0,sum=0,MIN=1000000000+5;
        for(int i=0;i<n;++i){
            cin >> arr[i];
            sum+=arr[i];
            MAX=max(MAX,arr[i]);
            MIN=min(MIN,arr[i]);
        }
        cout << max(MAX,(int)ceil(sum/(double)(n-1)))*(n-1)-sum << '\n';
    }
    
    return 0;
}