#include <bits/stdc++.h>
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl '\n'
#define pb push_back
const ll MOD = 1e9 + 7;
using namespace std;
 
vector<int> seg;
 
void update(int node, int l, int r, int idx, int v){
	if(r == l){
		seg[node] = v % MOD;
		return;
	}
 
	int m = (l + r) / 2;
 
	if( idx < m )
		update( node*2  , l, m, idx, v);
	else 
		update( node*2+1, m+1, r, idx, v);
 
	seg[node] = (seg[node*2] + seg[node*2+1]) % MOD;
}
 
int query(int node, int l, int r, int ql, int qr){
	if( ql <= l && r <= qr) return seg[node];
	if( r < ql || qr < l) return 0;
 
	int m = (l + r) / 2;
 
	return (query(node*2  , l, m, ql, qr)
				+ query(node*2+1, m+1, r, ql, qr)) % MOD;
 
}
 
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	vector<int> pos;
	for(int &i : a) cin >> i, pos.pb(i);

	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	for(int &i : a) i = lower_bound(pos.begin(),pos.end(),i) - pos.begin();
 
	vector<int> dp(n,0);
	seg.assign(n * 4, 0);
	for(int x : a){
		int prev = query(1,0,n,0,x);
		dp[x] += prev + 1;
		dp[x] %= MOD;
		update(1,0,n,x,dp[x]);
	}

	// for(int i : seg) cout << i << " ";
	// cout << endl;
 
	cout << accumulate(dp.begin(),dp.end(),0ll) % MOD << endl;
}
 
int main(){
	fastio;
	solve();
	return 0;
}
