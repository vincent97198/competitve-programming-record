#include <bits/stdc++.h>
#define ll long long
#define N 1030

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int arr[N];
        vector<int> v;
        for(int i=0;i<n;++i){
            cin >> arr[i];
            v.emplace_back(arr[i]);
        }

        sort(v.begin(),v.end());
        bool flag;
        for(int i=1;i<2*1024;++i){
            flag=true;
            vector<int> tmp;
            for(int j=0;j<n;++j)
                tmp.emplace_back(arr[j]^i);
            sort(tmp.begin(),tmp.end());
            for(int i=0;i<n;++i){
                if(tmp[i]!=v[i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout << i << endl;
                break;
            }
        }
        if(!flag)
            cout << -1 << endl;
    }

    return 0;
}

