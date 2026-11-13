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

vector<int> seg;

void update(int node, int l, int r, int idx, char c){
	if( r - l == 1 ){
		seg[node] = (1<<c);
		return;
	}
	int mid = (l + r) / 2;
	if( idx < mid )
		update(2*node  , l, mid, idx, c);
	else
		update(2*node+1, mid, r, idx, c);
	seg[node] = seg[2*node] | seg[2*node+1];
}

int query(int node, int l, int r, int ql, int qr){
	if( qr <= l || r <= ql) return 0;
	if( ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	return query(2*node, l, mid, ql, qr) | query(2*node+1, mid, r, ql, qr);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	string a; cin >> a;
	int n, m; cin >> m;
	n = a.size();
	seg.assign(4*n, 0);
	for(int i = 0; i < n; i++)
		update(1,0,n,i,a[i]);
	for(int i = 0; i < m; i++){
		int t; cin >> t;
		if( t == 1 ){
			int p; cin >> p;
			char c; cin >> c;
			update(1,0,n,p-1,c);
		} else{
			int l, r; cin >> l >> r;
			cout << __builtin_popcount(query(1,0,n,l-1,r)) << endl;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

