#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int a,b,c,ans=0,MAXANS=0,tmpa,tmpb,tmpc;
		cin >> tmpa >> tmpb >> tmpc;
		int num[7]={1,2,3,4,5,6,7};
		do{
		    ans=0;
		    a=tmpa; b=tmpb; c=tmpc;
            for(int i=0;i<7;++i){
                int A=(num[i]&4)>>2,B=(num[i]&2)>>1,C=num[i]&1;
                if(a>=A && b>=B && c>=C){
                    ++ans;
                    a-=A;	b-=B;	c-=C;
                }
            }
            MAXANS=max(MAXANS,ans);
		}while(next_permutation(num,num+7));

		cout << MAXANS << endl;
	}

	return 0;
}

