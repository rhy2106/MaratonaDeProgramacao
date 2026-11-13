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

double dp[2000001][22];
int n;

ld f(ll cur, ll delta){
	if( cur <= 0 || cur >= 2*n ) return 0.0;
	double &ret = dp[cur][delta];
	if( ret >= 0 ) return ret;
	ret = 0;
	int bit = (1 << delta);
	ret = 1 + (0.5 * f(cur + bit, 0)) + (0.5 * f(cur - bit, delta+1));
	return ret;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	cin >> n;
	memset(dp,-1,sizeof(dp));
	cout << fixed << setprecision(12) << f(n,0) << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

