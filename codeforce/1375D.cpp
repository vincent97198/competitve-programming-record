#include <bits/stdc++.h>
#define N 5005
#define ll long long

using namespace std;

int a[N];

int main()
{
    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;
        int cnt[N],now=0,pos=0; memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;++i){
            cin >> a[i];    ++cnt[a[i]];
            while(cnt[now]!=0)  ++now;
        }
        multiset<int> tmp;
        for(int i=0;i<n;++i)    tmp.insert(i),tmp.insert(i);
        vector<int> ans;
        bool flag;
        while(!tmp.empty()){
            flag=true;
            while(now+1>n){
                auto iter=tmp.begin();
                while(*iter!=*next(iter)) ++iter;
                flag=false;
                ans.push_back(*iter+1);
                --cnt[a[*iter]],++cnt[now];
                int TMP=now;
                if(cnt[a[*iter]]==0) now=min(a[*iter],now);
                while(cnt[now]!=0)  ++now;
                a[*iter]=TMP;
                tmp.erase(iter);
            }
            if(flag){
                ans.push_back(now+1);
                tmp.erase(now);
                --cnt[a[now]],++cnt[now];
                if(cnt[a[now]]==0)    now=min(a[now],now);
                while(cnt[now]!=0)  ++now;
            }
        }
        cout << ans.size() << endl;
        for(int i:ans)  cout << i << " ";
        cout << endl;
    }

    return 0;
}

/*
 * 8 4 7 6 1 2 3 0 5
 * 9 4 7 6 1 2 3 0 5
 * 9 4 7 6 1 2 3 0 8
 * 9 4 7 6 1 5 3 0 8
 * 9 4 2 6 1 5 3 0 8
 * 9 4 2 6 1 5 3 7 8
 * 0 4 2 6 1 5 3 7 8
 * 0 9 2 6 1 5 3 7 8
 * 0 9 2 6 4 5 3 7 8
 * 0 1 2 6 4 5 3 7 8
 *
 * 0 6 5 3 4 4 3
 * 0 1 5 3 4 4 3
 * 0 1 5 3 4 4 2
 */
