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
	int n; cin >> n;
	vector<iPair> a;
	vector<int> pos;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		a.pb({x,y});
		pos.pb(x);
		pos.pb(y);
	}
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	auto get = [&](int x){
		return lower_bound(pos.begin(),pos.end(),x) - pos.begin();
	};

	vector<int> pref_sum(pos.size(),0);
	int maior = 0;
	for(int i = 0; i < n; i++){
		pref_sum[get(a[i].f)]++;
		pref_sum[get(a[i].s)]--;
	}

	for(int i = 1; i < pref_sum.size(); i++){
		pref_sum[i] += pref_sum[i-1];
		maior = max(maior,pref_sum[i]);
	}
	cout << maior << endl;
	
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

