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

vector<iTuple> seg;

void update(int node, int l, int r, int idx, int val){
	if(r - l == 1){
		seg[node] = {val,1,val};
		return;
	}
	int mid = (l + r) / 2;
	if( idx < mid )
		update(2*node  , l, mid, idx, val);
	else
		update(2*node+1, mid, r, idx, val);

	int gcd = __gcd( get<2>(seg[2*node]), get<2>(seg[2*node+1]));

	if(get<0>(seg[2*node]) < get<0>(seg[2*node+1]))
		seg[node] = {get<0>(seg[2*node]), get<1>(seg[2*node]), gcd};
	else if(get<0>(seg[2*node]) > get<0>(seg[2*node+1]))
		seg[node] = {get<0>(seg[2*node+1]), get<1>(seg[2*node+1]), gcd};
	else
		seg[node] = {get<0>(seg[2*node]), get<1>(seg[2*node]) + get<1>(seg[2*node+1]), gcd};
}

iTuple query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return {INF,0,0};
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	iTuple a, b;
	a = query(2*node  , l, mid, ql, qr);
	b = query(2*node+1, mid, r, ql, qr);
	if(get<2>(a) == -1) return b;
	if(get<2>(b) == -1) return a;

	int gcd = __gcd(get<2>(a),get<2>(b));
	if(get<0>(a) < get<0>(b))
		return {get<0>(a), get<1>(a), gcd};
	else if(get<0>(a) > get<0>(b))
		return {get<0>(b), get<1>(b), gcd};
	else 
		return {get<0>(a), get<1>(a) + get<1>(b), gcd};
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	vector<int> a(n);
	seg.assign(4*n,{INF,0,0});
	for(int i = 0; i < n; i++){
		cin >> a[i];
		update(1,0,n,i,a[i]);
	}
	int m; cin >> m;
	while(m--){
		int l, r; cin >> l >> r;
		iTuple tmp = query(1, 0, n, l-1, r);
		if(get<0>(tmp) == get<2>(tmp)) cout << r - (l-1) - get<1>(tmp) << endl;
		else cout << r - (l-1) << endl;
	}

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

