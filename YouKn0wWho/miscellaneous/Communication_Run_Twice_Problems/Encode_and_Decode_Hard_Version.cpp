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

void first_case(){
	int n; cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		int j = 10 - a[i].size();
		for(int k = 0; k < j; k++) cout << 'a';
		for(int k = 0; k < a[i].size(); k++) cout << (char)(a[i][k] - '0' + 'a');
	}
	cout << endl;
}

void second_case(){
	string s; cin >> s;
	int i = 0;
	cout << s.size()/10 << endl;
	while( i < s.size() ){
		int num = 0;
		for(int j = 0; j < 10; j++){
			num *= 10;
			num += s[i + j] - 'a';
		}
		cout << num << " ";
		i += 10;
	}
	cout << endl;
}

void solve(){
	string s; cin >> s;
	if( s == "first" ) first_case();
	else second_case();
	
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	solve();
    return 0;
}

