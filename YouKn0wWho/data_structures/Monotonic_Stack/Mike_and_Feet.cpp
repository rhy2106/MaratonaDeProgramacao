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

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	ll n; cin >> n;
	vector<ll> a(n), l(n), r(n);
	stack<ll> s;
	for(ll &i : a) cin >> i;

	for(int i = 0; i < n; i++){
		while( !s.empty() && a[s.top()] >= a[i] ) s.pop();
		if( s.empty() ) l[i] = 0;
		else l[i] = s.top() + 1;
		s.push(i);
	}

	while( !s.empty() ) s.pop();

	for(int i = n-1; i >= 0; i--){
		while( !s.empty() && a[s.top()] >= a[i] ) s.pop();
		if( s.empty() ) r[i] = n + 1;
		else r[i] = s.top() + 1;
		s.push(i);
	}
	vector<pair<int,int>> ans;
	for(int i = 0; i < n; i++){
		int indice = r[i] - l[i] - 1;
		ans.pb({a[i], indice});
	}
	sort(ans.rbegin(),ans.rend());
	int id = 1;
	for(int i = 0; i < n; i++){
		while( id <= n && id <= ans[i].s ){
			cout << ans[i].f << " ";
			id++;
		}
	}
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

