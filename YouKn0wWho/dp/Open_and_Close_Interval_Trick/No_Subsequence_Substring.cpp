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

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	string s, t; cin >> s >> t;
	ll ans = 0;
	vector<ll> dp(t.size()+1,0);
	for(char c : s){
		dp[0]++;
		vector<ll> ndp(t.size()+1,0);
		for(int k = 0; k < t.size(); k++){
			int nk = (c == t[k] ? k+1 : k);
			ndp[nk] = ndp[nk] + dp[k];
		}
		for(int i = 0; i < t.size(); i++) ans += ndp[i];
		dp.swap(ndp);
	}

	cout << ans << endl;
	
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

