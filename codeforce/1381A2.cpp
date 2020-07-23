#include <bits/stdc++.h>
#define N 200003
#define ll long long

using namespace std;

int n;
string a,b;

void init()
{
    cin >> n;
    cin >> a >> b;
}

void solve()
{
    vector<int> ans;
    bool flag=true;
    int front_now=a[0]-'0',now,indexFront=0,indexBack=n;
    for(int i=n-1;i>=0;--i){
        //if(a[i]==b[i]) continue;
        now=b[i]-'0';
        if(now==front_now)
            ans.emplace_back(1);
        ans.emplace_back(i+1);
        if(flag)
            front_now=((a[--indexBack]-'0')^1);
        else
            front_now=(a[++indexFront]-'0');
        flag^=true;
    }
    if(ans.empty())
        cout << 0 << endl;
    else{
        cout << ans.size() << " ";
        for(int i=0;i<ans.size();++i)
            cout << ans[i] << " ";
        cout << endl;
    }
}

int main()
{
    int t;  cin >> t;
    while(t--){
        init();
        solve();
    }

    return 0;
}

/*
 * 01011
 * 11011 1
 * 00100 5
 * 10100 1
 * 10100 4
 * 00100 1
 * 01100 3
 * 11100 1
 *
 *
 * 12345
 * 54321
 * 23451
 * 43251
 */
