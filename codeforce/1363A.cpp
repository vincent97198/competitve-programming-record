#include <bits/stdc++.h>
#define N 10000

using namespace std;

int main()
{
	int t,n,x;
	bool odd;
	cin >> t;
	while(t--){
		cin >> n >> x;
		int tmp,ODD=0,EVEN=0;	bool odd=false;
		for(int i=0;i<n;++i){
			cin >> tmp;
			if(tmp%2)
				++ODD;
			else
				++EVEN;
		}

   		bool flag=false;
		for(int i=0;i<=x;++i){
			if(ODD>=i && i%2==1 && x-i<=EVEN)
				flag=true;
		}
		if(flag)
			cout << "Yes";
		else
			cout << "No";
/*
   		if(ODD==0){
			cout << "No\n";
			continue;
		}
		if(ODD%2==0)
			ODD--;
		if(x>=ODD && x-ODD<=EVEN)
			cout << "Yes";
		else if(x<=ODD && EVEN>=1)
			cout << "Yes";
		else
			cout << "No";
*/
		cout << endl;
	}
	return 0;
}
