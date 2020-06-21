#include <bits/stdc++.h>
#define ll long long
#define N 55

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int T;  cin >> T;
    while(T--){
        ll x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (x2-x1)*(y2-y1)+1 << endl;
    }

    return 0;
}
