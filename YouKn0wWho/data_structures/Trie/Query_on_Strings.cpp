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

const int MAXN = 1e5 + 5;
multiset<int> pref_count[MAXN];

struct Trie{
	map<char,Trie> children;
	int P = 0;

	void insert(const string& s, int pos) {
		if( P )
			pref_count[pos].erase( pref_count[pos].find(P) );
		P++;
		pref_count[pos].insert( P );
		if (pos == s.size()) return;
		children[s[pos]].insert(s, pos+1);
	}

	void remove(const string& s, int pos) {
		pref_count[pos].erase( pref_count[pos].find(P) );
		P--;
		if ( P > 0 ) pref_count[pos].insert( P );
		if (pos == s.size()) return;
		children[s[pos]].remove(s, pos+1);
	}
};

void solve(){
	int q; cin >> q;
	Trie trie;
	map<int,string> a;
	for(int i = 1; i <= q; i++) {
		int t; cin >> t;
		if ( t == 1 ) {
			string s; cin >> s;
			reverse(s.begin(),s.end());
			a[i] = s;
			trie.insert(s, 0);
		} else if ( t == 2 ) {
			int k, l; cin >> k >> l;
			cout << ( !pref_count[l].empty() && *pref_count[l].rbegin() >= k ? "YES" : "NO" ) << endl;
		} else {
			int x; cin >> x;
			if ( a.count(x) ) {
				trie.remove( a[x], 0 );
				a.erase(x);
			}
		}
	}
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	// fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
    return 0;
}

