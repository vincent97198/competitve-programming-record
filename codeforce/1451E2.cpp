#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = (1LL<<17)+5;
int n,ans[N];
vector<int> arr[N];

signed main()
{
	cin >> n;
	for(int i=2;i<=n;++i){
		cout << "XOR 1 " << i << endl;
		int tmp;	cin >> tmp;
		arr[tmp].push_back(i);
	}

	bool flag=false;	//if same?
	int SAME;
	for(int i=0;i<N;++i){
		if(arr[i].size()>1 || (i==0 && !arr[0].empty())){
			flag=true;
			SAME=i;
			break;
		}
	}

	if(flag){
		if(SAME!=0)
			cout << "AND " << arr[SAME][0] << " " << arr[SAME][1] << endl;
		else
			cout << "AND " << arr[SAME][0] << " " << 1 << endl;
		int tmp;
		cin >> tmp;	ans[1]=tmp^SAME;
	}
	else{
		cout << "AND 1 " << arr[1][0]  << endl;
		int tmp1,tmp2;	cin >> tmp1;
		cout << "AND 1 " << arr[2][0] << endl;
		cin >> tmp2;
		ans[1]=tmp1;
		ans[1]|=(tmp2&1);
	}

	for(int i=0;i<N;++i){
		for(int j=0;j<arr[i].size();++j)
			ans[arr[i][j]]=ans[1]^i;
	}
	cout << "!";
	for(int i=1;i<=n;++i)
		cout << " " << ans[i];
	cout << endl;

}