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
	vector<int> id, super;
	DSU(int n){
		id.assign(n,0);
		super.assign(n,0);
		iota(id.begin(),id.end(),0);
	}
	
	int find(int x){
		if(id[x] != x){
			find(id[x]);
			super[x] = super[x] + super[id[x]];
			id[x] = id[id[x]];
		}
		return id[x];
	}

	void unir(int x, int y){
		x = find(x), y = find(y);
		if( x == y ) return;
		id[x] = y;
		super[x] = 1;
	}
};

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	
	int n, m; cin >> n >> m;
	DSU a(n);
	for(int i = 0; i < m; i++){
		int t, x, y; cin >> t;
		if( t == 1 ){
			cin >> x >> y; x--, y--;
			a.unir(x,y);
		} else{
			cin >> x; x--;
			a.find(x);
			cout << (a.id[x] == x ? a.super[x] : a.super[x] + a.super[a.id[x]]) << endl;
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

