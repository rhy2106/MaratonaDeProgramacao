#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

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

using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<
	T,
	null_type,
	less<T>,
	rb_tree_tag,
	tree_order_statistics_node_update
>;

vector<int> primes;
void pre_calc(){
	int maxn = 1e6 + 5;
	vector<int> p(maxn, 0);
	for(int i = 2; i < maxn; i++){
		if( p[i] ) continue;
		primes.pb(i);
		for(int j = i; j < maxn; j+=i)
			p[j] = 1;
	}
}

void solve(int testCase){
	cout << "Case " << testCase << ": ";
	ll n, k; cin >> n >> k;
	int m = (1<<k);
	vector<ll> a(k);
	for(ll &i : a) cin >> i;
	if( n == 0 ){
		cout << n << endl;
		return; 
	}
	ll ans = 0;
	for(int mask = 0; mask < m; mask++){
		ll tmp = 1;
		for(int i = 0; i < k; i++)
			if(mask&(1<<i)) tmp = tmp * a[i];
		ans += ( ( __builtin_popcount(mask) & 1 ) ? -1 : 1 ) * n / tmp;
	}
	int all_primes = upper_bound(primes.begin(),primes.end(),n) - primes.begin() + 1;
	for(int i = 0; i < k; i++)
		if( a[i] <= n ) all_primes--;
	ans -= all_primes;
	cout << ans << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	pre_calc();
	int tt = 1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
	return 0;
}

