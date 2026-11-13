#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define f first
#define s second
#define endl '\n'
#define pb push_back

using namespace std;

struct SegTree{
	vector<ll> seg;

	SegTree(vector<ll>& a){
		seg.assign(4*a.size(),0);
		build(0,0,a.size(),a);
	}
	
	void build(int node, int l, int r, vector<ll>& a){
		if( r - l == 1){
			seg[node] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(2*node+1, l, mid, a);
		build(2*node+2, mid, r, a);
		seg[node] = max(seg[2*node+1],seg[2*node+2]);
	}

	ll query(int node, int l, int r, int ql, int qr){
		if( r <= ql || qr <= l ) return  0;
		if( ql <= l && r <= qr ) return seg[node];
		int mid = (l + r) >> 1;
		ll ans = 0;
		ans = max(ans, query(2*node+1, l, mid, ql, qr));
		ans = max(ans, query(2*node+2, mid, r, ql, qr));
		return ans;
	}
};

void solve(int testCase){
	int n; cin >> n;
	vector<ll> a(n);
	for(ll &i : a) cin >> i;
	SegTree seg(a);
	int q; cin >> q;
	while(q--){
		int m; cin >> m;
		stack<ll> s;
		vector<ll> b(m), c;
		ll ans = 0;
		for(ll &i : b){
			cin >> i; i--;
			ans += a[i];
		}
		for(int i = 1; i < m;i++)
			c.pb( seg.query(0,0,n,b[i-1],b[i]+1) );
		m--;
		vector<ll> l(m), r(m);
		for(int i = 0 ; i < m; i++){
			while(!s.empty() && c[s.top()] <= c[i]) s.pop();
			if( s.empty() ) l[i] = i + 1;
			else l[i] = i - s.top();
			s.push(i);
		}
		while(!s.empty()) s.pop();
		for(int i = m-1; i >= 0; i--){
			while(!s.empty() && c[s.top()] < c[i]) s.pop();
			if( s.empty() ) r[i] = m - i;
			else r[i] = s.top() - i;
			s.push(i);
		}

		for(int i = 0; i < m; i++)
			ans += l[i] * r[i] * c[i];

		cout << ans << endl;
	}
}

int main(){
	fastio;
	int tt = 1;
	for(int t = 1; t <= tt; t++) solve(t);
	return 0;
}


