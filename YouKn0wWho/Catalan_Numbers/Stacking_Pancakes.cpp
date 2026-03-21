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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll dp[1000+5][1000+5];
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1]) % MOD;
        }
    }
	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		ll ans = 0;
		for (int j = 1; j <= n; j++) {
			(ans += dp[n][j]) %= MOD;
		}

		cout << ans << "\n";
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}


