#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,s,k,tmp;
		set<int> st;
		cin >> n >> s >> k;
		for(int i=0;i<k;++i){
			cin >> tmp;
			st.insert(tmp);
		}
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			tmp=q.front();	q.pop();
			if(st.find(tmp)==st.end()){
				cout << abs(tmp-s) << endl;
				break;
			}
			else{
				if(tmp>1 && tmp<=s)
					q.push(tmp-1);
				if(tmp<n && tmp>=s)
					q.push(tmp+1);
			}
		}
	}

	return 0;
}
