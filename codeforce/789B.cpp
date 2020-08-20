#include<bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

int main()
{
    ll b,q,l,m;    cin >> b >> q >> l >> m;
    set<ll> s;
    for(int i=0;i<m;++i){
        ll tmp; cin >> tmp;
        s.insert(tmp);
    }
    if(abs(b)>l){
        cout << "0\n";
        return 0;
    }
    if(q==0 || b==0){
        if(s.find(0)==s.end())
            cout << "inf" << endl;
        else if(b==0)
            cout << "0\n";
        else if(s.find(b)==s.end())
            cout << "1\n";
        else
            cout << "0\n";
    }
    else if(q==1){
        if(s.find(b)==s.end())
            cout << "inf" << endl;
        else
            cout << "0\n";
    }
    else if(q==-1){
        if(s.find(b)==s.end() || s.find(-b)==s.end())
            cout << "inf\n";
        else
            cout << "0\n";
    }
    else{
        int ans=0;
        while(abs(b)<=l){
            if(s.find(b)==s.end())
                ++ans;
            b*=q;
        }
        cout << ans << endl;
    }
}

