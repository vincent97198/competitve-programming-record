#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505;
int arr[N],re[N];

signed main()
{
    int t;  cin >> t;
    while(t--){
        int n,x;    cin >> n >> x;
        int tmp=-1;
        
        for(int i=0;i<N;++i)
            re[i]=n;
        
        for(int i=0;i<n;++i){
            cin >> arr[i];
            re[arr[i]]=min(re[arr[i]],i);
        }
        
        int ans=0;
        for(int i=x+1;i<N;++i){
            if(re[i]!=n){
                swap(arr[re[i]],x);
                i=x;
                ++ans;
                for(int i=0;i<n;++i)
                    cout << arr[i] << " ";
                cout << endl;
            }
        }
        
        bool flag=true;
        for(int i=0;i<n;++i){
            if(i>0 && arr[i-1]>arr[i]){
                flag=false;
            }
        }
        if(flag)
            cout << ans << '\n';
        else
            cout << "-1\n";
    }
    
    return 0;
}

/*
x=5
1 4 5 7 7 6

x=5
1 2 4 6 6 10 8 9

1 2 4 5 6  7 8 9 10
*/