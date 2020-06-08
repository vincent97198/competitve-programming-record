#include <bits/stdc++.h>
#define N 1003

using namespace std;

int n,k;

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<int> s[N];
        int total=0;
        for(int i=0;i<k;++i){
            int sz;	cin >> sz;
            total+=sz;
            for(int j=0;j<sz;++j){
                int tmp;	cin >> tmp;
                s[i].push_back(tmp);
            }
        }

        cout << "? " << n << " ";
        for(int i=1;i<=n;++i)
            cout << i << " ";
        cout << endl;
        int MAX;
        cin >> MAX;

        int l=0,r=k-1;
        while(r>l){
            int mid=(l+r)/2,size0=0;
            for(int i=l;i<=mid;++i)
                size0+=s[i].size();
            cout << "? " << size0 << " ";
            for(int i=l;i<=mid;++i)
                for(int j=0;j<s[i].size();++j)
                    cout << s[i][j] << " ";
            cout << endl;
            int tmpMAX;	cin >> tmpMAX;
            if(tmpMAX==MAX)
                r=mid;
            else
                l=mid+1;
        }

        sort(s[l].begin(),s[l].end());
        cout << "? " << n-s[l].size() << " ";
        for(int i=1,now=0;i<=n;++i){
            if(now<s[l].size() && s[l][now]==i)
                ++now;
            else
                cout << i << " ";
        }

        cout << endl;
        int MAX2;	cin >> MAX2;

        cout << "! ";
        for(int i=0;i<k;++i){
            if(i!=l)
                cout << MAX;
            else
                cout << MAX2;
            cout << " ";
        }
        cout << endl;
        string tmp;
        cin >> tmp;
        if(tmp=="Incorrect")
            break;
    }
}

