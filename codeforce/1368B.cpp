#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    ll k;   cin >> k;

    ll cnt=0,tmp=pow(k,0.1);
    cnt=pow(tmp,10);
    int num=0;
    while(cnt<k){
        ++num;
        cnt=cnt/tmp*(tmp+1);
    }
    string ans="codeforces";
    for(int i=0;i<num;++i)
        for(int j=0;j<tmp+1;++j)
            cout << ans[i];
    for(int i=num;i<10;++i)
        for(int j=0;j<tmp;++j)
            cout << ans[i];
    cout << endl;

    return 0;
}
