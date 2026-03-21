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

const int M = 20;
const int maxM = (1<<M);

ll freq[maxM];
ll s[maxM];
ll dp[maxM];

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		int m = 0, y = n;
		for(int i = n; i > 0; i >>= 1) m++;
		if(m > 20) m = 20;
		int maxn = (1<<m);

		for(int i = 0; i < maxn; i++){
			freq[i] = 0;
			dp[i] = 0;
		}

		for(int i = 0; i < n; i++){
			ll x; cin >> x;
			freq[x]++;
		}

		for (int i = 0; i < m; i++) {
			for (int mask = maxn - 1; mask >= 0; mask--) {
				if(mask & (1 << i)) continue;
				freq[mask] += freq[mask | (1 << i)];
			}
		}
		for (int mask = maxn - 1; mask >= 0; mask--) {
			dp[mask] = (ll)mask * freq[mask];

			for (int i = 0; i < m; i++) {
				if(mask & (1 << i)) continue;
				int supermask = mask | (1 << i);
				dp[mask] = max(dp[mask], dp[supermask] + (ll)mask * (freq[mask] - freq[supermask]));
			}
		}

		ll ans = 0;
		for(int i = 0; i < maxn; i++)
			ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
