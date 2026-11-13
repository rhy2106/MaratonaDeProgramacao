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

string l, r;
ll dp[11][22][2][2];

ll f(int pos, int c, int tl,int tr){
	if(pos == l.size()) return c;
	ll &ans = dp[pos][c][tl][tr];
	if(ans != -1) return ans;
	ans = INF;
	int liml = (tl ? l[pos]-'0' : 0);
	int limr = (tr ? r[pos]-'0' : 9);
	for(int i = liml; i <= limr; i++){
		int ntl = tl & ( i == liml );
		int ntr = tr & ( i == limr );
		int nc = c + (ntl ? 1 : 0) + (ntr ? 1 : 0);
		ans = min(ans, f(pos+1, nc, ntl, ntr));
	}
	return ans;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		cin >> l >> r;
		memset(dp,-1,sizeof(dp));
		cout << f(0,0,1,1) << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

