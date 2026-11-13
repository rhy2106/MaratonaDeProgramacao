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

void update(int node, int l, int r, int idx, int val){
	if(r - l == 1){
		seg[node] = val;
		return;
	}
	int mid = (l + r) / 2;
	if( idx < mid )
		update(2*node  , l, mid, idx, val);
	else
		update(2*node+1, mid, r, idx, val);
	seg[node] = seg[2*node] & seg[2*node+1];
}

int query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return (1<<30)-1;
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	return query(2*node, l, mid, ql, qr) & query(2*node+1, mid, r, ql, qr);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n, m; cin >> n >> m;
	vector<iTuple> queries;
	for(int i = 0; i < m; i++){
		int l, r, q; cin >> l >> r >> q;
		l--;
		queries.emplace_back(l,r,q);
	}
	vector<int> a(n,0), sum(n,0);
	for(int b = 0; b < 30; b++){
		for(int i = 0; i < n; i++) sum[i] = 0;
		for(int i = 0; i < m; i++){
			if( get<2>(queries[i]) & (1<<b) ){ 
				sum[get<0>(queries[i])] += 1;
				if(get<1>(queries[i]) < n) sum[get<1>(queries[i])]--;
			}
		}
		for(int i = 1; i < n; i++)
			sum[i] += sum[i-1];
		for(int i = 0; i < n; i++)
			if(sum[i] > 0) a[i] |= (1<<b);
	}

	seg.assign(4*n,(1<<30)-1);
	for(int i = 0; i < n; i++)
		update(1,0,n,i,a[i]);

	bool erro = false;
	for(auto [l,r,q] : queries){
		int tmp = query(1,0,n,l,r);
		if( q != tmp) erro = true;
	}
	if(erro) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

