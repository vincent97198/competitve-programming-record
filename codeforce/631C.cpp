#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N=200005;

struct op
{
    int r,type,index;
};

int n,m,a[N];

bool cmp(op a,op b)
{
    if(a.r!=b.r)
        return a.r>b.r;
    return a.index>b.index;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    vector<op> vtmp;
    for(int i=0;i<m;++i){
        int rtmp,typetmp;   cin >> typetmp >> rtmp;

