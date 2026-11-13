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
	int maior, qnt;
	vector<int> id, floresta;
	
	DSU(int n){
		maior = 1;
		qnt = n;
		id.assign(n,0);
		floresta.assign(n,1);
		iota(id.begin(),id.end(),0);
	}

	int find(int x){
		return id[x] = ((id[x] == x) ? x : find(id[x]));
	}

	void unir(int x, int y){
		x = find(x); y = find(y);
		if( x == y ) return;
		if( floresta[x] < floresta[y] ) swap(x,y);
		floresta[x] += floresta[y];
		id[y] = x;
		maior = max(maior, floresta[x]);
		qnt--;
	}
};

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	int n, m; cin >> n >> m;
	DSU a(n);
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		a.unir(x,y);
		cout << a.qnt << " " << a.maior << endl;
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

