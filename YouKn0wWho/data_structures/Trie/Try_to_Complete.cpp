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

struct Trie{
	map<char,Trie> children;
	int P = 0;
	int best_qnt = 0;
	string best = "";

	int insert(const string& s, int pos){
		if(pos == s.size()){
			P++;
			if( P > best_qnt ){
				best = s;
				best_qnt = P;
			}
		if( P == best_qnt ) {
			best = min(best, s);
		}
			return P;
		}

		int qnt = children[s[pos]].insert(s,pos + 1);
		
		if( qnt > best_qnt ) {
			best_qnt = qnt;
			best = s;
		}
		if( qnt == best_qnt ) {
			best = min(best, s);
		}
		return qnt;
	}

	pair<string,int> query(const string& s, int pos){
		if( pos == s.size() ) return {best,best_qnt};
		return children[s[pos]].query(s,pos+1);
	}
};

void solve(){
	int n; cin >> n;
	Trie trie;
	while(n--){
		string s; cin >> s;
		trie.insert(s,0);
	}
	int q; cin >> q;
	while(q--){
		string s; cin >> s;
		pair<string,int> ans = trie.query(s,0);
		cout << (ans.s == 0 ? "-1" : ans.f  + " "  + to_string(ans.s)) << endl;
	}
	
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

