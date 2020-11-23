#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
    
    int t;  cin >> t;
    while(t--){
        int n,c0,c1,h;  cin >> n >> c0 >> c1 >> h;
        string s;   cin >> s;
        
        int A=0,B=0;
        for(int i=0;i<n;++i){
            if(s[i]=='0')
                ++A;
            else
                ++B;
        }
        
        cout << min(min(A*c0+B*c1,(A+B)*c0+h*B),(A+B)*c1+h*A) << '\n';
    }
    
    return 0;
}