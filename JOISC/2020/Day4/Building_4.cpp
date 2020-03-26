#include <bits/stdc++.h>
#define ll long long
#define N 500005

using namespace std;

struct item{
  int MIN=1e9,MAX=-1e9;
};

int n,A[N*2],B[N*2];
item dp[2*N][2];

void update(item &now,item &pre,int val)
{
    now.MIN=min(now.MIN,pre.MIN+val);
    now.MAX=max(now.MAX,pre.MAX+val);
}

bool check(item now,int val)
{
    return now.MAX>=val && now.MIN<=val;
}

void init()
{
    cin >> n;
    for(int i=0;i<2*n;++i)
        cin >> A[i];
    for(int i=0;i<2*n;++i)
        cin >> B[i];
}

void solve()
{
    dp[0][0]=item{1,1},dp[0][1]=item{0,0};	//dp[i][j]	i->position,j->last number is from A(0) or B(1),dp[][]->the range of number of A
    for ( int i = 0; i < 2 * n - 1; ++i ) {
        for ( int j = 0; j < 2; ++j ) {
            if ( j == 0 && A[i + 1] >= A[i] )
                update( dp[i + 1][0], dp[i][j], 1 );
            if ( j == 1 && A[i + 1] >= B[i] )
                update( dp[i + 1][0], dp[i][j], 1 );
            if ( j == 0 && B[i + 1] >= A[i] )
                update( dp[i + 1][1], dp[i][j], 0 );
            if ( j == 1 && B[i + 1] >= B[i] )
                update( dp[i + 1][1], dp[i][j], 0 );
        }
    }

    if ( !check( dp[2 * n - 1][0], n ) && !check( dp[2 * n - 1][1], n ) ) {
        cout << -1 << endl;
        return ;
    }

    string s;
    bool pre;
    int num = n;
    A[2 * n] = B[2 * n] = 1e9;
    for ( int i = 2 * n - 1; i >= 0; --i ) {
        if ( check( dp[i][0], num ) && A[i] <= (pre ? B[i + 1] : A[i + 1]) ) {
            s += "A";
            --num;
            pre = false;
        }
        else {
            s += "B";
            pre = true;
        }
    }

    reverse( s.begin(), s.end() );

    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );

    init();
    solve();

    return 0;
}
