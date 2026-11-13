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

vector<ll> a;

vector<ll> get_sum(int l, int r){
	int tam = r-l+1;
	vector<ll> soma;

	for(int mask = 0; mask < (1<<tam); mask++){
		ll total = 0;
		for(int i = 0; i < tam; i++)
			if(mask & (1<<i)) total += a[l+i];
		soma.pb(total);
	}
	return soma;
} 

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll n, x; cin >> n >> x;
	a.assign(n,0);
	for(ll &i : a) cin >> i;

	vector<ll> l, r;
	l = get_sum(0, n/2-1);
	r = get_sum(n/2, n-1);
	ll ans = 0;
	sort(l.begin(),l.end());
	sort(r.begin(),r.end());
	for(ll i : l){
		auto hi = upper_bound(r.begin(),r.end(),x-i);
		auto lo = lower_bound(r.begin(),r.end(),x-i);
		ans += hi - lo;
	}
	cout << ans << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

