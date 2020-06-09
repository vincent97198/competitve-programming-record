#include <bits/stdc++.h>
#define N 100005

using namespace std;

int main()
{
	int n,arr[N];
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i];

	set<int> s,vis;
	vector<int> ans(n);
	int now=-1;
	for(int i=0;i<n;++i){
		if(s.empty()){
			++now;
			vis.clear();
		}

		if(arr[i]>0){
			if(s.find(arr[i])!=s.end() || vis.find(arr[i])!=vis.end()){
				cout << -1 << endl;
				return 0;
			}
			else
				s.insert(arr[i]);
		}
		else{
			if(s.find(-arr[i])!=s.end()){
				s.erase(s.find(-arr[i]));
				vis.insert(-arr[i]);
			}
			else{
				cout << -1 << endl;
				return 0;
			}
		}

		++ans[now];
	}
	if(!s.empty()){
		cout << -1 << endl;
		return 0;
	}
	cout << now+1 << endl;
	for(int i=0;i<=now;++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}

