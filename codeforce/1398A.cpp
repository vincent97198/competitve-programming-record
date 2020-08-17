#include <bits/stdc++.h>
#define ll long long
#define N 50005

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int arr[N];
        for(int i=0;i<n;++i)
            cin >> arr[i];
        if(arr[0]+arr[1]<=arr[n-1])
            cout << 1 << " " << 2 << " " << n << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
