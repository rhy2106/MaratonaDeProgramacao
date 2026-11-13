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

struct DSU{
	vector<int> id, floresta;
	DSU(int n){
		id.assign(n,0);
		floresta.assign(n,1);
		iota(id.begin(),id.end(),0);
	}

	int find(int x){
		return id[x] = (id[x] == x ? x : find(id[x]));
	}

	void unir(int x, int y){
		x = find(x); y = find(y);
		if( x == y ) return;
		if( y > x ) swap(x,y);
		floresta[x] += floresta[y];
		id[y] = x;
	}
};

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	int n, m, k; cin >> n >> m >> k;
	DSU a(n);
	for(int x, y, i = 0; i < m; i++) cin >> x >> y;
	vector<tuple<string,int,int>> queries;
	for(int i = 0; i < k; i++){
		string t; cin >> t;
		int u, v; cin >> u >> v;
		u--; v--;
		queries.emplace_back(t,u,v);
	}
	vector<bool> ans;
	reverse(queries.begin(),queries.end());
	for(auto [t, u, v] : queries){
		if(t == "cut") a.unir(u,v);
		else ans.pb( a.find(u) == a.find(v) );
	}
	reverse(ans.begin(), ans.end());
	for(bool i : ans)
		cout << ( i ? "YES" : "NO" ) << endl;
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

