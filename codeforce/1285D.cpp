#include <bits/stdc++.h>
#define N 200003
#define ll long long

using namespace std;

int n,a[N],Mx=0;

int dfs(vector<int> &v,int depth)
{
    if(depth<0) return 0;
    vector<int> l,r;
    for(int i:v){
        if(((i>>depth)&1)==0)
            l.emplace_back(i);
        else
            r.emplace_back(i);
    }
    if(l.empty())
        return dfs(r,depth-1);
    else if(r.empty())
        return dfs(l,depth-1);
    return min(dfs(l,depth-1),dfs(r,depth-1))+(1<<depth);
}

int main()
{
    cin >> n;
    vector<int> tmp;
    for(int i=0;i<n;++i){
        cin >> a[i];
        tmp.emplace_back(a[i]);
    }

    cout << dfs(tmp,30) << endl;

    return 0;
}

/*
 *
 */
