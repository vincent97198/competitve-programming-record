#include <bits/stdc++.h>
#define N 200005
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);

    int t;  cin >> t;
    while(t--){
        string s;   cin >> s;
        int S=0,P=0,R=0;
        for(int i=0;i<s.size();++i)
            if(s[i]=='S')   ++S;
            else if(s[i]=='R')  ++R;
            else    ++P;

        if(S>=R && S>=P){
            for(int i=0;i<s.size();++i)
                cout << "R";
        }
        else if(R>=P && R>=S){
            for(int i=0;i<s.size();++i)
                cout << "P";
        }
        else{
            for(int i=0;i<s.size();++i)
                cout << "S";
        }
        cout << endl;
    }

    return 0;
}
