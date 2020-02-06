#include <bits/stdc++.h>
#define ll long long
#define N 20005

using namespace std;

struct doll{
	int h,w;
}arr[N];

int n;

bool cmp(doll a,doll b)
{
	if(a.h==b.h)
		return a.w>b.w;
	
	return a.h<b.h;
}

void init()
{
	cin >> n;
	for(int i=0;i<n;++i)
		cin >> arr[i].w >> arr[i].h;
}


void solve()
{
	sort(arr,arr+n,cmp);
	
	vector<int> v;
	v.push_back(arr[0].w);

	for(int i=1;i<n;++i){
		if(v.back()<arr[i].w)
			v.push_back(arr[i].w);
		else
			*lower_bound(v.begin(),v.end(),arr[i].w)=arr[i].w;
	}

	cout << v.size() << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;	cin >> t;
	while(t--){
		init();
		solve();
	}

	return 0;
}
