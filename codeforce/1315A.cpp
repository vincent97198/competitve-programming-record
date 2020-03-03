#include <bits/stdc++.h>
#define ll long long
#define N 200005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        ll a,b,x,y,area=0;
        cin >> a >> b >> x >> y;
        area=max((a-x-1)*b,x*b);
        area=max(area,max(y*a,(b-y-1)*a));
        cout << area << endl;
    }

    return 0;
}

