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

ll f(vector<ll>& a, vector<ll>& b, ll x){
	ll cnt = 0;

	for(ll i : a)
		cnt += max( x - i, 0ll );
	for(ll i : b)
		cnt += max( i - x, 0ll );

	return cnt;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	
	ll l = 0, r = 1e9;
	while( r - l > 2){
		ll m1 = l + (r-l)/3;
		ll m2 = r - (r-l)/3;
		ll f1 = f(a,b,m1);
		ll f2 = f(a,b,m2);
		if( f1 > f2 ) l = m1;
		else r = m2;
	}
	ll ans = min( f(a,b,l), f(a,b,l+1));
	cout << ans << endl;
	
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	while(tt--) solve();
    return 0;
}

