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
	int pos = n;
	int d = 1;
	int ans = 0;
	while( true ){
		if( n < m && n + d >= m ){
			ans += m - pos;
			break;
		}
		if( n > m && n + d <= m ){
			ans += pos - m;
			break;
		}
		ans += abs(pos - (n+d));
		pos = n + d;
		d *= -2;
	}
	cout << ans << endl;
}

int main(){
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
	return 0;
}

