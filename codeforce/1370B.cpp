#include <bits/stdc++.h>
#define ll long long
#define N 2005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int arr[N];
        vector<int> odd,even;   odd.reserve(n),even.reserve(n);
        for(int i=0;i<2*n;++i){
            cin >> arr[i];
            if(arr[i]&1)
                odd.emplace_back(i+1);
            else
                even.emplace_back(i+1);
        }
        int ODD=odd.size()/2,EVEN=even.size()/2;
        if(even.empty())
            --ODD;
        else if(even.size()%2==0)
            --EVEN;
        for(int i=0;i<ODD*2;i+=2)
            cout << odd[i] << " " << odd[i+1] << '\n';
        for(int i=0;i<EVEN*2;i+=2)
            cout << even[i] << " " << even[i+1] << '\n';
    }

    return 0;
}
