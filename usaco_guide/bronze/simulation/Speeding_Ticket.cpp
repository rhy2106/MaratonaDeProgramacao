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

void solve(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>> a(n), b(m);
	for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
	for(int i = 0; i < m; i++) cin >> b[i].f >> b[i].s;

	int maior = 0;
	int i = 0, j = 0;
	while( i < n && j < m){
		int tmp = min(a[i].f, b[j].f);
		maior = max( maior, b[j].s - a[i].s );
		a[i].f -= tmp;
		b[j].f -= tmp;
		if( a[i].f == 0 ) i++;
		if( b[j].f == 0 ) j++;
	}

	cout << maior << endl;
	
}

int main(){
	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
	return 0;
}

