#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        deque<char> dq;
        dq.push_front(s[0]);
        int pos=0;
        bool v[26],f=false;
        memset(v,0,sizeof(v));
        v[s[0]-'a']=true;
        for(int i=1;i<s.size();++i){
            if(!v[s[i]-'a']){
                if(pos==dq.size()-1){
                    dq.push_back(s[i]);
                    ++pos;
                }
                else if(pos==0)
                    dq.push_front(s[i]);
                else{
                    cout << "NO" << endl;
                    f=true;
                    break;
                }
            }
            else{
                if(pos>0 && dq[pos-1]==s[i])
                    --pos;
                else if(pos<dq.size()-1 && dq[pos+1]==s[i])
                    ++pos;
                else{
                    cout << "NO" << endl;
                    f=true;
                    break;
                }
            }
            v[s[i]-'a']=true;
        }
        if(f)
            continue;
        else{
            cout << "YES" << endl;
            for(int i=0;i<26;++i)
                if(!v[i])
                    cout << (char)(i+'a');

            for(int i=0;i<dq.size();++i)
                cout << dq[i];
        }
        cout << endl;
    }

    return 0;
}

