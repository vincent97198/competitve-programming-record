#include <bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

struct lecture{
	int sa,sb,ea,eb;
};

struct event{
	int isIN,s,e,t;
};

int n;
lecture arr[N];

bool cmp(event x,event y)
{
	if(x.t==y.t)
		return x.isIN<y.isIN;
	return x.t<y.t;
}

void solve()
{
	multiset<int> s,e;
	vector<event> v;
	for(int i=0;i<n;++i){
		v.push_back(event{1,arr[i].sb,arr[i].eb,arr[i].sa});
		v.push_back(event{0,arr[i].sb,arr[i].eb,arr[i].ea+1});
	}
	sort(v.begin(),v.end(),cmp);

	for(int i=0;i<2*n;++i){
		if(v[i].isIN){
			if(!s.empty() && !e.empty()){

				auto tmpMAX=s.rbegin();
				auto tmpMIN=e.begin();
				if(*tmpMAX>v[i].e || *tmpMIN<v[i].s){
					cout << "NO" << endl;
					exit(0);
				}
			}
			s.insert(v[i].s);
			e.insert(v[i].e);
		}
		else{
			s.erase(s.find(v[i].s));
			e.erase(e.find(v[i].e));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i].sa >> arr[i].ea >> arr[i].sb >> arr[i].eb;

	solve();
	
	for(int i=0;i<n;++i){
		swap(arr[i].sa,arr[i].sb);
		swap(arr[i].ea,arr[i].eb);
	}

	solve();

	cout << "YES" << endl;
	

	return 0;
}
