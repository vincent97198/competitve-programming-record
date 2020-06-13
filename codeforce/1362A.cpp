#include <bits/stdc++.h>
#define ll long long
#define N 505

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        ll a,b; cin >> a >> b;
        if(b>a){
            int ans=0;
            while(b>a){
                a<<=1;
                ++ans;
            }
            if(a==b)
                cout << ceil(ans/3.0) << endl;
            else
                cout << -1 << endl;
        }
        else{
            int ans=0;
            while(a>b){
                if((a&1)==0)
                    a>>=1;
                else
                    break;
                ++ans;
            }
            if(a==b)
                cout << ceil(ans/3.0) << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}

