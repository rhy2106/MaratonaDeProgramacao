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
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for(int &i : a) cin >> i;
	map<int,vector<pair<int,int>>> m;
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
			m[a[i] + a[j]].pb({i,j});

	for(auto [key, value] : m){
		if( m.contains( x - key ) ){
			for(pair<int,int> p : value){
				for(pair<int,int> q : m[x-key]){
					set<int> b = {p.f, p.s, q.f, q.s};
					if( b.size() == 4){
						for(int i : b) cout << i+1 << " ";
						cout << endl;
						return;
					}
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
	return 0;
}

