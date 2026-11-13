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
int k, n;
vector<vector<int>> a;

bool ver( int i, int j ){
	if( k == 1 ) return true;

	for(int u = 1; u < k; u++){
		if( a[i][u-1] < a[j][u-1]
		&&	a[i][u] > a[j][u] )
			return false;

		if( a[i][u-1] > a[j][u-1]
		&&	a[i][u] < a[j][u] )
			return false;
	}
	return true;
}

void solve(){
	cin >> k >> n;

	a.assign(n,vector<int>());
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			int x; cin >> x; x--;
			a[x].pb(j);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if( ver( i, j ) ) ans++;
		}
	}
	cout << ans << endl;
	
}

int main(){
	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
	return 0;
}

