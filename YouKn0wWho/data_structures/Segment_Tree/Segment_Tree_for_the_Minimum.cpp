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
vector<int> seg;

void build(vector<int>& a, int node, int l, int r){
	if(r - l == 1){
		seg[node] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(a, 2*node  , l, mid);
	build(a, 2*node+1, mid, r);
	seg[node] = min(seg[2*node], seg[2*node+1]);
}

void update(int node, int l, int r, int idx, int val){
	if(r-l == 1){
		seg[node] = val;
		return;
	}
	int mid = (l + r) / 2;
	if(idx < mid) update(2*node, l, mid, idx, val);
	else update(2*node+1, mid, r, idx, val);
	seg[node] = min(seg[2*node], seg[2*node+1]);
}

int query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return INF;
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	return min( query(2*node, l, mid, ql, qr), query(2*node+1,mid,r,ql,qr) );
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    _;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	seg.assign(4*n,0);
	build(a,1,0,n);
	while(m--){
		int q; cin >> q;
		if( q == 2 ){
			int l, r; cin >> l >> r;
			cout << query(1, 0, n, l, r) << endl;
		} else{
			int i, v; cin >> i >> v;
			update(1, 0, n, i, v);
		}
	}
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

