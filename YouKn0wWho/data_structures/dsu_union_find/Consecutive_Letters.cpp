#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define uset unordered_set
#define umap unordered_map

using namespace std;

struct DSU{
	vector<int> id, floresta;

	DSU(int n){
		id.assign(n,0);
		floresta.assign(n,1);
		iota(id.begin(),id.end(),0);
	}

	int find(int x){
		return id[x] = (id[x] == x ? x : find(id[x]));
	}
	
	void unir(int x, int y, char c){
		x = find(x), y = find(y);
		if(x == y) return;
		if(floresta[x] < floresta[y]) swap(x,y);
		floresta[x] += floresta[y];
		id[y] = x;
	}
};

void solve(int testCase){
	cout << "Case " << testCase << ":" << endl;

	string s; cin >> s;
	int q; cin >> q;

	int n = s.size();
	string cur_s = s;
	vector<pair<int,int>> queries;
	vector<int> ans;

	for(int i = 0; i < q; i++){
		int t, x; cin >> t >> x;
		if( t == 2 ) cur_s[x] = '#';
		queries.pb({t,x});
	}

	DSU a(n);

	for(int i = 1; i < n; i++){
		if( cur_s[i] == '#' ) continue;
		if( cur_s[i-1] == cur_s[i] )
			a.unir(i-1, i, cur_s[i]);
	}

	reverse(queries.begin(),queries.end());
	for(auto [t, x] : queries){
		if( t == 1 ){
			ans.pb( a.floresta[a.find(x)]);
		} else {
			cur_s[x] = s[x];
			if( x > 0 
					&& cur_s[x] != '#'
					&& cur_s[x] == cur_s[x-1]
				) a.unir(x, x-1, cur_s[x]);
			if( x < n-1
					&& cur_s[x] != '#'
					&& cur_s[x] == cur_s[x+1]
				) a.unir(x, x+1, cur_s[x]);
		}
	}
	reverse(ans.begin(),ans.end());

	for(int i : ans)
		cout << i << endl;
	
}

int main(){
	fastio;
	int tt = 1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
	return 0;
}

