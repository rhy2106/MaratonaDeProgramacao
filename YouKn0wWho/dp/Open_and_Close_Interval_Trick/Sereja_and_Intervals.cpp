#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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
const ld eps = 1e-9;
const ld PI = 3.14159265359;

using namespace std;

void solve(){
	int n, m, x; cin >> n >> m >> x;

	if( n > m ){
		cout << 0 << endl;
		return;
	}
	// vector [qnt intervalo][qnt aberto]
	// sempre fecha o mais antigo
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	if( x != 1 )
		dp[0][0] = 1;

	for(int i = 2; i <= m; i++){
		vector<vector<int>> ndp(n+1,vector<int>(n+1,0));
		for(int j = 0; j <= n; j++){
			for(int k = 0; k <= n; k++){
				int v = dp[j][k];
				// abre e fecha
				if( j < n && k == 0 ) ndp[j+1][k] = (ndp[j+1][k] + v) % MOD;
				// abre
				if( j < n && k < n ) ndp[j+1][k+1] = (ndp[j+1][k+1] + v) % MOD;
				// fecha 
				if( k > 0 && i != x ) ndp[j][k-1] = (ndp[j][k-1] + v) % MOD;
				// fecha e abre
				if( j < n && k > 0 ) ndp[j+1][k] = (ndp[j+1][k] + v) % MOD;
				// nao faz nd
				if( i != x ) ndp[j][k] = (ndp[j][k] + v) % MOD;
			}
		}
		dp.swap(ndp);
	}
	
	ll ans = 1;
	for(ll i = 1; i <= n; i++)
		ans = (ans * i) % MOD;

	cout << (dp[n][0] * ans) % MOD << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
    return 0;
}

