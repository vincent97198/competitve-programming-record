#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   int t;   cin >> t;
   while(t--){
       string s;    cin >> s;
       int x;   cin >> x;
       string ans,check;
       for(int i=0;i<s.size();++i){
           ans+='1';
           check+='0';
       }
       
       for(int i=0;i<s.size();++i){
           if(s[i]=='0'){
               if(i-x>=0)
                   ans[i-x]='0';
               if(i+x<s.size())
                   ans[i+x]='0';
           }
       }
       for(int i=0;i<ans.size();++i){
           if(ans[i]=='1'){
               if(i-x>=0)
                   check[i-x]='1';
               if(i+x<ans.size())
                   check[i+x]='1';
           }
       }
       if(check==s)
           cout << ans << endl;
       else
           cout << -1 << endl;
   }
}

