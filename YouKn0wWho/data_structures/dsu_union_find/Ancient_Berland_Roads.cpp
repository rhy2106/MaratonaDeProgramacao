#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define iPair pair<ll,ll>
using namespace std;

struct DSU{
	vector<ll> id, floresta, people;
	multiset<ll> maior;

	DSU(ll n, vector<ll>& p){ // n logn
		id.assign(n,0);
		floresta.assign(n,1);
		people.assign(n,0);
		iota(id.begin(),id.end(),0);
		for(int i = 0; i < n; i++){ 
			people[i] = p[i];
			maior.insert(people[i]);
		}
	}

	ll find(ll x){
		return id[x] = (id[x] == x ? x : find(id[x]));
	}

	void unir(ll x, ll y){ // logn
		x = find(x), y = find(y);
		if(x == y) return;
		if(floresta[x] < floresta[y]) swap(x,y);
		floresta[x] += floresta[y];
		id[y] = x;
		maior.erase(maior.find(people[x]));
		maior.erase(maior.find(people[y]));
		people[x] += people[y];
		maior.insert(people[x]);
	}

	void update(ll x, ll old, ll val){ // logn
		x = find(x);
		maior.erase(maior.find(people[x]));
		people[x] -= old;
		people[x] += val;
		maior.insert(people[x]);
	}
};

void solve(int testCase){
	// cout << "Case " << testCase << ":" << endl;
	ll n, m, q; cin >> n >> m >> q;
	vector<ll> people(n);
	vector<pair<ll,ll>> roads(m);
	vector<bool> destroyed(m,false);
	vector<tuple<char,ll,ll>> queries;

	for(int i = 0; i < n; i++) cin >> people[i];

	for(int i = 0; i < m; i++){
		cin >> roads[i].f >> roads[i].s;
		roads[i].f--; roads[i].s--;
	}

	for(int i = 0; i < q; i++){ // q
		char t; cin >> t;
		ll x, p = 0;
		if( t == 'D' ){
			cin >> x; x--;
			destroyed[x] = true;
		} else{
			cin >> x >> p; x--;
			swap(p, people[x]);
		}
		queries.emplace_back(t,x,p);
	}

	DSU a(n,people); // nlogn

	for(int i = 0; i < m; i++) // m logn
		if( !destroyed[i] )
			a.unir(roads[i].f,roads[i].s);

	reverse(queries.begin(),queries.end()); // n

	vector<ll> ans;

	for(auto [t, x, p] : queries){ // q logn
		ans.pb(*a.maior.rbegin());
		if( t == 'D' ){
			a.unir(roads[x].f, roads[x].s);
		} else {
			a.update(x,people[x],p);
			people[x] = p;
		}
	}

	reverse(ans.begin(),ans.end()); // q

	for(ll i : ans) // q
		cout << i << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
	fastio;
	int tt = 1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
	return 0;
}

