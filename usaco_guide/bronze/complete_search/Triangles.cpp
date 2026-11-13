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

int calc_area(vector<pair<int,int>> a, int i, int j, int k){
	int area = 0;
	if( a[k].f == a[j].f && a[i].s == a[k].s ) area = (a[k].s-a[j].s) * (a[i].f-a[k].f);
	if( a[i].f == a[j].f && a[j].s == a[k].s ) area = (a[i].s-a[j].s) * (a[k].f-a[j].f);
	if( a[i].f == a[j].f && a[i].s == a[k].s ) area = (a[i].s-a[j].s) * (a[i].f-a[k].f);
	return abs(area);
}

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> a(n);
	for(int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;

	int area = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if( i != j && j != k && i != k )
				area = max(area, calc_area(a, i, j, k));
	cout << area << endl;
	
}

int main(){
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
	return 0;
}

