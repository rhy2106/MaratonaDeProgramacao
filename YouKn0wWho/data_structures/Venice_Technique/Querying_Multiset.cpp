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

struct VeniceSet{
	multiset<ll> v;
	ll water = 0;
	void add(ll x){ v.insert(x - water); }
	void pop(ll x){ v.erase(v.find(x - water)); }
	void updateAll(ll x){ water += x; }
	void prll(){
		cout << "water: " << water << endl;
		for(ll i : v){
			cout << i << " ";
		}
		cout << endl;
	}
	ll getMin(){ return *v.begin() + water; }
};


void solve(){
	ll q; cin >> q;
	VeniceSet s;
	while( q-- ){
		ll t, x; cin >> t;
		if(t == 1){
			cin >> x;
			s.add(x);
		} else if(t == 2){
			cin >> x;
			s.updateAll(x);
		} else{
			cout << s.getMin() << endl;
			s.pop(s.getMin());
		}
	}
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	solve();
    return 0;
}

