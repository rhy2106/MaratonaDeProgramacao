#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<ll,ll>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple>, greater<iTuple>>
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

using namespace std;

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll N, M; cin >> N >> M;
	ll total = 0;
	vector<iPair> ruas;
	while(M--){
		ll x, k; cin >> x >> k;
		x %= N;
		x = min(x, N-x);
		if(x == 0) continue;
		ruas.pb(mp(k,x));
	}
	sort(ruas.begin(),ruas.end());
	if(N % ruas[0].s != 0){
		total = ruas[0].f * (N-1);
		cout << total << endl;
		return 0;
	}
	total = ruas[0].f * (N - N/ruas[0].s);
	for(auto [w,x] : ruas){
		if(x % ruas[0].s == 0) continue;
		total += w * (N/ruas[0].s - 1);
		cout << total << endl;
		return 0;
	}
	cout << -1 << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

