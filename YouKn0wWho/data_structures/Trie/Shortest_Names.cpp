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

const int MAXN = 1e6 + 5;
int pref_names[MAXN];

struct Trie{
	map<char,Trie> children;
	int words = 0;
	int depth = 0;

	void insert(const string& s, int pos, bool inprefix) {
		words++;
		depth = pos;
		if (words == 1 && !inprefix) {
			inprefix = true;
			pref_names[depth]++;
		}
		if (words == 2) {
			pref_names[depth]--;
			pref_names[depth+1]++;
		}
		if( pos == s.size() ) return;
		children[s[pos]].insert(s, pos + 1, inprefix);
	}
};

void solve(){
	int n; cin >> n;
	Trie trie;
	memset(pref_names, 0, sizeof(pref_names));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		trie.insert(s, 0,false);
	}
	ll ans = 0;
	for (int i = 0; i < MAXN; i++)
		ans += pref_names[i] * i;
	cout << ans << endl;
	
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	int tt = 1;
	cin >> tt;
	while(tt--) solve();
    return 0;
}

