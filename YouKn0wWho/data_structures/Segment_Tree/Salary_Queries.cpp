#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define mp make_pair
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<int,int>
#define iTuple tuple<int,int,int>
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue <iTuple, vector<iTuple, greater<iTuple>>

using namespace std;

vector<int> seg;

void update(int node, int l, int r, int idx, int val){
	if(r - l == 1){
		seg[node] += val;
		return;
	}
	int mid = (l + r) / 2;
	if(idx < mid)
		update(2*node  , l, mid, idx, val);
	else
		update(2*node+1, mid, r, idx, val);
	seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int l, int r, int ql, int qr){
	if(qr <= l || r <= ql) return 0;
	if(ql <= l && r <= qr) return seg[node];
	int mid = (l + r) / 2;
	return query(2*node, l, mid, ql, qr) + query(2*node+1, mid, r, ql, qr);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

	vector<int> a(n);
	vector<iTuple> q;
	vector<int> vals;

	for(int i = 0; i < n; i++){
		cin >> a[i];
		vals.pb(a[i]);
	}
	for(int i = 0; i < m; i++){
		char c; int x, y;
		cin >> c >> x >> y;

		q.emplace_back((c == '!' ? 0 : 1), x, y);
		vals.pb(y);
		if(c == '?') vals.pb(x);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(),vals.end()), vals.end());
	auto get = [&](int x){
		return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
	};
	int tam = vals.size();
	seg.assign(4*tam, 0);
	for(int i = 0; i < n; i++)
		update(1, 0, tam, get(a[i]),1);
	
	for(auto [t, x, y] : q){
		if(!t){
			x--;
			update(1,0,tam,get(a[x]),-1);
			a[x] = y;
			update(1,0,tam,get(a[x]), 1);
		} else{
			cout << query(1,0,tam,get(x),get(y)+1) << endl;	
		}
	}
}

