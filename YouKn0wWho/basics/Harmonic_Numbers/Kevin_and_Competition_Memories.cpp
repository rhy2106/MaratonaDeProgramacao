#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		ll n, m; cin >> n >> m;
		ll a[n], b[m], c[m];
		for(ll &i : a) cin >> i;
		for(ll &i : b) cin >> i;
		ll k = a[0];
		sort(a, a + n);
		sort(b, b + m);
		
		for(int i = 0; i < m; i++){
			c[i] = 1;
			if( b[i] <= k ) continue;
			auto hi = lower_bound(a, a + n, b[i]) - a;
			c[i] += n - hi;
		}

		sort(c, c + m);
		
		for(int i = 1; i <= m; i++){
			ll ans = 0;
			for(int j = i; j <= m; j+=i){
				ans += c[j-1];
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

