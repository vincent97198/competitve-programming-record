#include <bits/stdc++.h>
#define ll long long
#define N 50005

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;

        vector<int> tmp;
        int pre=0,cnt=0;
        for(int i=0;i<s.size();++i){
            int now=s[i]-'0';
            if(now!=pre){
                if(pre==1)
                    tmp.push_back(cnt);
                pre=now;
                cnt=now;
            }
            else
                cnt+=now;
        }
        if(s[s.size()-1]=='1')
            tmp.push_back(cnt);
        sort(tmp.begin(),tmp.end());
        int ans=0;
        for(int i=tmp.size()-1;i>=0;i-=2)
            ans+=tmp[i];
        cout << ans << endl;
    }
    return 0;
}
