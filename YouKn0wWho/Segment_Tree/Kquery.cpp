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

int query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return 0;
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	return query(2*node, l, mid, ql, qr) + query(2*node+1, mid, r, ql, qr);
}

struct Query{
	int i, j, k, id;
};
int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	vector<iPair> a(n);
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		a[i] = mp(x,i);
	}

	int q; cin >> q;
	vector<Query> queries;
	for(int s = 0; s < q; s++){
		int i, j, k; cin >> i >> j >> k;
		Query tmp;
		tmp.i = i;
		tmp.j = j;
		tmp.k = k;
		tmp.id = s;
		queries.pb(tmp);
	}

	seg.assign(4*n,0);

	sort(a.begin(), a.end(), greater<iPair>());
	sort(queries.begin(),queries.end(), [](auto a, auto b){
		return a.k > b.k;
	});

	vector<iPair> ans;

	int i = 0;
	for(Query q : queries){
		while( i < n && a[i].f > q.k ){
			update(1,0,n,a[i].s);
			i++;
		}
		ans.pb(mp(q.id,query(1,0,n,q.i-1,q.j)));
	}

	sort(ans.begin(),ans.end());

	for(int j = 0; j < ans.size(); j++)
		cout << ans[j].s << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

