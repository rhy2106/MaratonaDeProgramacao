#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
#define ld long double
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

void solve(){
	int k, n; cin >> k >> n;
	vector<iPair> filmes(k);
	for(int i = 0; i < k; i++)
		cin >> filmes[i].s >> filmes[i].f;
	sort(filmes.begin(), filmes.end());
	int cnt = 0;
	multiset<int> a;
	for(int i = 0; i < n; i++)
		a.insert(0);
	for(int i = 0; i < k; i++){
		auto it = a.upper_bound(filmes[i].s);
		if( it == a.begin() ) continue;
		it--;
		a.erase(a.find(*it));
		a.insert( filmes[i].f );
		cnt++;
	}
	cout << cnt << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
    return 0;
}

