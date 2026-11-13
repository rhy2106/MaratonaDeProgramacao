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

vector<ll> seg;

void update(int node, int l, int r, int idx){
	if(r - l == 1){
		seg[node]++;
		return;
	}
	int mid = (l + r) / 2;
	if(idx < mid)
		update(2*node  , l, mid, idx);
	else
		update(2*node+1, mid, r, idx);
	seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return 0;
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	return query(2*node, l, mid, ql, qr) + query(2*node+1, mid, r, ql, qr);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<int> val = a;
	sort(val.begin(),val.end());
	val.erase(unique(val.begin(),val.end()),val.end());
	auto get = [&](int x){
		return lower_bound(val.begin(),val.end(),x) - val.begin();
	};

	int m = val.size();

	vector<ll> left(n), right(n);

	seg.assign(4*m,0);

	for(int i = 0; i < n; i++){
		left[i] = query(1,0,m,get(a[i]),m);
		update(1,0,m,get(a[i]));
	}

	seg.assign(4*m,0);

	for(int i = n-1; i >= 0; i--){
		right[i] = query(1,0,m,0,get(a[i]));
		update(1,0,m,get(a[i]));
	}

	ll total = 0;
	for(int i = 0; i < n; i++){
		total += right[i]*left[i];
	}
	cout << total << endl;
	
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

