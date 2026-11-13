#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
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

int n, m;
vector<int> a;
vector<vector<int>> b;

vector<int> dp;

int upper(const vector<int> &c, int x){
	int l = -1, r = c.size();
	while(r - l != 1){
		int mid = (l + r) / 2;
		if(c[mid] > x) r = mid;
		else l = mid;
	}
	return r-1;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	freopen("movie.in", "r", stdin);
	freopen("movie.out", "w", stdout);
    _;
	cin >> n >> m;
	a.assign(n,0);
	b.assign(n,vector<int>());
	for(int i = 0; i < n; i++){
		int q; cin >> a[i] >> q;
		for(int j = 0; j < q; j++){
			int tmp; cin >> tmp;
			b[i].pb(tmp);
		}
	}
	dp.assign((1<<n),0);
	for(int mask = 0; mask < (1<<n); mask++){
		for(int j = 0; j < n; j++){
			if(mask & (1<<j)) continue;
			int nmask = mask | (1<<j);
			int i = upper(b[j], dp[mask]);
			if(i < 0) continue;
			dp[nmask] = max(b[j][i] + a[j], dp[nmask]);
		}
	}
	int ans = 30;
	for(int mask = 0; mask < (1<<n); mask++){
		// bitset<4> tmp(mask);;
		// cout << tmp << " ";
		// cout << setw(3) << dp[mask] << endl;
		if(dp[mask] >= m){
			ans = min(ans, __builtin_popcount(mask));
		}
	}
	cout << (ans == 30 ? -1 : ans) << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

