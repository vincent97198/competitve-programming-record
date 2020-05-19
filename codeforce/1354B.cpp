#include<bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int tmp[3]={-2000000,-2000000,-2000000},ans=2e6;
        for(int i=0;i<s.size();++i){
            tmp[s[i]-'1']=i;
            ans=min(ans,tmp[s[i]-'1']-min(tmp[(s[i]-'1'+1)%3],tmp[(s[i]-'1'+2)%3])+1);
        }
        if(ans!=2000000)
            cout << ans << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}

