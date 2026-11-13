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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll n, m, k; cin >> n >> m >> k;
	ll a[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	vector<vector<ll>> l(n);
	vector<vector<ll>> r(n);
	n--; m--;
	if(n == 0 && m == 0){
		cout << (a[0][0] == k ? 1 : 0) << endl;
		return 0;
	}
	for(ll mask = 0; mask < (1<<m); mask++){
		int cnt0 = 0;
		int cnt1 = 0;
		ll total = (m == 0 ? 0 : a[0][0]);
		for(ll i = 0; i < m; i++){
			if(mask & (1ll<<i)) cnt1++;
			else cnt0++;
			if(cnt0 > n) break;
			total ^= a[cnt0][cnt1];
		}
		if(cnt0 > n) continue;
		l[cnt0].pb(total);
	}

	for(ll mask = 0; mask < (1<<n); mask++){
		int cnt0 = 0;
		int cnt1 = 0;
		ll total = (n == 0 ? 0 : a[n][m]);
		for(ll i = 0; i < n; i++){
			if(mask & (1<<i)) cnt1++;
			else cnt0++;
			if(cnt1 > m) break;
			if(i == n-1 && m != 0) continue;
			total ^= a[n-cnt0][m-cnt1];
		}
		if(cnt1 > m) continue;
		r[n-cnt0].pb(total);
	}

	for(int i = 0; i <= n; i++){
		sort(l[i].begin(),l[i].end());
		sort(r[i].begin(),r[i].end());
	}

	ll ans = 0;
	for(int i = 0; i <= n; i++){
		for(ll j : l[i]){
			auto hi = upper_bound(r[i].begin(),r[i].end(),k^j);
			auto lo = lower_bound(r[i].begin(),r[i].end(),k^j);
			ans += hi - lo;
		}
	}
	cout << ans << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}


