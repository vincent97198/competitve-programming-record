#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int tmp;    map<int,int> mp;
        for(int i=0;i<n;++i){
            cin >> tmp; ++mp[tmp];
        }

        int MAX=0,MAX_num=0;
        for(auto iter=mp.begin();iter!=mp.end();++iter){
            if(iter->second>MAX)
                MAX=iter->second,MAX_num=1;
            else if(iter->second==MAX)
                ++MAX_num;
        }
        cout << (n-MAX*MAX_num)/(MAX-1)+MAX_num-1 << endl;
    }

    return 0;
}
