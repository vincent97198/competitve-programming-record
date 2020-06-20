#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int T;  cin >> T;
    while(T--){
        int a,b,n,ans=0;  cin >> a >> b >> n;
        while(a<=n && b<=n){
            ++ans;
            if(a<b)
                a+=b;
            else
                b+=a;
        }
        cout << ans << endl;
    }

    return 0;
}
