#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define ld long double
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;
const ll A = 911382323;
const ll B = 972663749;

using namespace std;

int n, t;
ld p;
ld dp[2001][2001];

ld f(int cur, ld prob, int ct){
	if( ct == t ) return (ld)cur * prob;
	if( cur == n ) return (ld)cur * prob;
	if( dp[cur][ct] != -1 ) return dp[cur][ct];
	dp[cur][ct] = 0;
	ld ans = ( f(cur+1, p*prob, ct+1) + f(cur, prob*(1.0-p), ct+1));
	return dp[cur][ct] = ans;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	cin >> n >> p >> t;
	for(int i = 0; i <= 2000; i++)
		for(int j = 0; j <= 2000; j++)
			dp[i][j] = -1;
	cout << fixed << setprecision(12);
	cout << f(0, 1, 0) << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

