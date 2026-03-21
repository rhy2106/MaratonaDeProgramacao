#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
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

using namespace std;

int n, m;
vector<iPair> seg;

void build(vector<int>& a, int node, int l, int r){
	if(r - l == 1){
		seg[node] = {a[l], 1};
		return;
	}
	int mid = (l + r) / 2;
	build(a, 2*node  , l, mid);
	build(a, 2*node+1, mid, r);
	if( seg[2*node].f == seg[2*node+1].f )
		seg[node] = { seg[2*node].f, seg[2*node].s + seg[2*node+1].s };
	else if( seg[2*node].f < seg[2*node+1].f)
		seg[node] = seg[2*node];
	else
		seg[node] = seg[2*node+1];
}

void update(int node, int l, int r, int idx, int val){
	if( r - l == 1){
		seg[node] = {val,1};
		return;
	}
	int mid = (l + r) / 2;
	if( idx < mid )
		update( 2*node  , l, mid, idx, val);
	else
		update( 2*node+1, mid, r, idx, val);

	if( seg[2*node].f == seg[2*node+1].f )
		seg[node] = { seg[2*node].f, seg[2*node].s + seg[2*node+1].s };
	else if( seg[2*node].f < seg[2*node+1].f)
		seg[node] = seg[2*node];
	else
		seg[node] = seg[2*node+1];
}

iPair query(int node, int l, int r, int ql, int qr){
	if( qr <= l || r <= ql )
		return {INF,0};
	if( ql <= l && r <= qr )
		return seg[node];

	int mid = (l + r) / 2;

	iPair a, b;
	a = query( 2*node  , l, mid, ql, qr );
	b = query( 2*node+1, mid, r, ql, qr );

	if( a.f == b.f )
		return { a.f, a.s + b.s };
	else if( a.f < b.f)
		return a;
	else
		return b;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	seg.assign(4*n,{0,0});
	build(a, 1, 0, n);
	while( m-- ){
		int q; cin >> q;
		if(q == 1){
			int i, v; cin >> i >> v;
			update(1,0,n,i,v);
		} else{
			int l, r; cin >> l >> r;
			iPair ans = query(1,0,n,l,r);
			cout << ans.f << " " << ans.s << endl;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

