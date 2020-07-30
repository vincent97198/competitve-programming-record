#include <bits/stdc++.h>
#define N 100005
#define ll long long

using namespace std;

int main()
{
    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;
        int MIN=1e9;
        for(int i=0;i<=9;++i){
            for(int j=0;j<=9;++j){
                bool cnt=false;
                int now=0;
                for(int pos=0;pos<s.size();++pos){
                    if(cnt){
                        if(s[pos]==j+'0')
                            cnt=false;
                        else
                            ++now;
                    }
                    else{
                        if(s[pos]==i+'0')
                            cnt=true;
                        else
                            ++now;
                    }
                }
                if(cnt && i!=j)
                    ++now;
                MIN=min(now,MIN);
            }
        }
        cout << MIN << endl;
    }

    return 0;
}

/*
 *
 */
