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

vector<pair<ll,int>> seg;
vector<ll> d;
vector<ll> a;

void build(int node, int l, int r){
	if(r - l == 1){
		seg[node] = {a[l],a[l]};
		return;
	}
	int mid = (l + r) / 2;
	build(2*node  , l, mid);
	build(2*node+1, mid, r);
	seg[node] = {seg[2*node].f + seg[2*node+1].f, max(seg[2*node].s, seg[2*node+1].s)};
}

void update(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return;
	if(seg[node].s <= 2) return;
	if(r - l == 1){
		seg[node] = {d[seg[node].f], d[seg[node].f]};
		return;
	}
	int mid = (l + r) / 2;
	update(2*node  , l, mid, ql, qr);
	update(2*node+1, mid, r, ql, qr);
	seg[node] = {seg[2*node].f + seg[2*node+1].f, max(seg[2*node].s, seg[2*node+1].s)};
}

pair<ll,int> query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return {0,0};
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	pair<ll,int> a, b;
	a = query(2*node  , l, mid, ql, qr);
	b = query(2*node+1, mid, r, ql, qr);
	return {a.f + b.f, max(a.s,b.s)};
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	d.assign(1e6 + 1, 1);
	for(int i = 2; i <= 1e6; i++)
		for(int j = i; j <= 1e6; j+=i)
			d[j]++;
	int n, m; cin >> n >> m;
	a.assign(n,0);
	seg.assign(4*n,{0,0});
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1,0,n);
	for(int i = 0; i < m; i++){
		int t, l, r; cin >> t >> l >> r;
		if(t == 1)
			update(1, 0, n, l-1, r);
		else
			cout << query(1, 0, n, l-1, r).f << endl;
	}

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

