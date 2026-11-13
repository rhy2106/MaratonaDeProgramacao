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
	less_equal<T>,
	rb_tree_tag,
	tree_order_statistics_node_update
>;

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	int n; cin >> n;
	int a[n];
	ordered_set<int> b;
	umap<int,int> left, right;
	ll ans = 0;
	for(int &i : a) cin >> i;
	for(int i = n-1; i >= 0; i--){
		right[a[i]]++;
		b.insert(right[a[i]]);
	}
	for(int i = 0; i < n; i++){
		left[a[i]]++;
		int l = left[a[i]];
		int r = right[a[i]];
		right[a[i]]--;
		b.erase(b.upper_bound(r));
		ans += b.order_of_key(l);
	}
	cout << ans << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
	return 0;
}

