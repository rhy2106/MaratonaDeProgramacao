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
const ld eps = 1e-9;
const ld PI = 3.14159265359;

using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	int x, a, b, c; cin >> x >> a >> b >> c;
	vector<ll> v(n);
	v[0] = x;
	for(int i = 1; i < n; i++)
		v[i] = ( a * v[i-1] + b) % c;
	deque<int> minid;
	for(int i = 0; i < k; i++){
		while( !minid.empty() && v[minid.back()] >= v[i] )
			minid.pop_back();
		minid.push_back(i);
	}
	ll ans = v[minid.front()];
	for(int i = k; i < n; i++){
		while( !minid.empty() && minid.front() <= i-k )
			minid.pop_front();
		while( !minid.empty() && v[minid.back()] >= v[i] )
			minid.pop_back();
		minid.push_back(i);
		ans ^= v[minid.front()];
	}
	cout << ans << endl;
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

