#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define N 1000002

using namespace std;

int n,q,BIT[N];

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int pos,int val)
{
    for(;pos<N;pos+=lowbit(pos))
        BIT[pos]+=val;
}

int sum(int pos)
{
    int res=0;
    for(;pos>0;pos-=lowbit(pos))
        res+=BIT[pos];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   cout.tie(nullptr);
	cin >> n >> q;
	for(int i=0;i<n;++i){
	    int tmp;    cin >> tmp;
	    add(tmp,1);
	}

	while(q--){
	    int k;  cin >> k;
	    if(k>0)
	        add(k,1);
	    else{
	        k=-k;
            int res=0;
            for(int i=(1<<(int)log2(N));i;i>>=1)
                if(res+i<=N && BIT[res+i]<k)
                    k-=BIT[res+=i];
            ++res;
            add(res,-1);
	    }
    }

	if(sum(N-1)==0)
	    cout << 0;
    else{
        int k=1;
        int res=0;
        for(int i=(1<<(int)log2(N));i;i>>=1)
            if(res+i<=N && BIT[res+i]<k)
                k-=BIT[res+=i];
        ++res;
        cout << res;
    }
    cout << endl;

	return 0;
}

