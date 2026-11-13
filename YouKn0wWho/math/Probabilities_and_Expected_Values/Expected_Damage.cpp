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
const ll MOD = 998244353;
const ll A = 911382323;
const ll B = 972663749;

using namespace std;

ll fastpow(ll b, ll e){
	ll r = 1;
	while(e > 0){
		if(e & 1) r = (r * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return r;
}

ll inv( ll x ){
	return fastpow( x, MOD - 2);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, m; cin >> n >> m;
	vector<int> d(n,0);
	for(int i = 0; i < n; i++) cin >> d[i];
	sort(d.begin(),d.end());
	vector<int> sum(n+1,0);
	for(int i = 0; i < n; i++) sum[i+1] = (d[i] + sum[i]) % MOD;
	while(m--){
		int a, b; cin >> a >> b;
		int index = int(lower_bound(d.begin(), d.end(), b) - d.begin());
		int big = n - index;

		ll soma_maior = (sum[n] - sum[index] + MOD) % MOD;
		ll soma_menor = (sum[index] + MOD) % MOD;

		ll pmaior = ((soma_maior * (big - a)     ) % MOD* inv(big) ) % MOD;
		ll pmenor = ((soma_menor * (big + 1 - a) ) % MOD* inv(big + 1) ) % MOD;
		ll ans = (pmaior + pmenor) % MOD;
		if(a > big || a >= n) ans = 0;

		cout << ans << endl;
	}


	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

