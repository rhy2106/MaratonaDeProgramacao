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
		int n; cin >> n;
		ll a[n+2]; a[0] = -LINF; a[n+1] = LINF;
		for(ll i = 1; i <= n; i++) cin >> a[i];

		ll b[n+2], c[n+2];
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));

		for(int i = 1; i <= n; i++)
			b[i] += b[i-1] + (a[i] - a[i-1] < a[i-1] - a[i-2] ? 1 : a[i]-a[i-1]);
		for(int i = n; i >= 1; i--)
			c[i] += c[i+1] + (a[i+1] - a[i] < a[i+2] - a[i+1] ? 1 : a[i+1]-a[i]);

		int q; cin >> q;
		while(q--){
			int l, r; cin >> l >> r;
			ll ans = 0;
			if( l < r )
				cout << b[r] - b[l] << endl;
			else 
				cout << c[r] - c[l] << endl;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

