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

vector<pair<iPair,iPair>> seg;

pair<iPair,iPair> maior(iPair p1, iPair p2, iPair p3, iPair p4){
	vector<iPair> a;
	a.pb(p1); a.pb(p2);
	a.pb(p3); a.pb(p4);
	sort(a.begin(),a.end(), greater<iPair>());
	for(int i = 0; i < a.size(); i++){
		if( i+1 == a.size() ) break;
		if(a[i].f == a[i+1].f){
			a[i].s += a[i+1].s;
			a.erase(a.begin() + i + 1);
			i--;
		}
	}
	return {a[0],a[1]};
}

void update(int node, int l, int r, int idx, int val){
	if(r - l == 1){
		seg[node] = {{val,1},{0,0}};
		return;
	}
	int mid = (l + r) / 2;
	if(idx < mid)
		update(2*node  , l, mid, idx, val);
	else
		update(2*node+1, mid, r, idx, val);

	seg[node] = maior(
		seg[2*node].f,
		seg[2*node].s,
		seg[2*node+1].f,
		seg[2*node+1].s
		);
}

pair<iPair,iPair> query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return {{0,0},{0,0}};
	if(ql <= l && r <= qr) return seg[node];

	int mid = (l + r) / 2;

	pair<iPair,iPair> a = query(2*node  , l, mid, ql, qr);
	pair<iPair,iPair> b = query(2*node+1, mid, r, ql, qr);

	return maior(a.f,a.s,b.f,b.s);
}
int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, q; cin >> n >> q;
	vector<int> a(n);
	seg.assign(4*n,{{0,0},{0,0}});
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++)
		update(1,0,n,i,a[i]);

	while(q--){
		int t; cin >> t;
		if(t == 2){
			int l, r; cin >> l >> r;
			cout << query(1, 0, n, l-1, r).s.s << endl;
		} else{
			int i, v; cin >> i >> v;
			update(1, 0, n, i-1, v);
		}
	}

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

