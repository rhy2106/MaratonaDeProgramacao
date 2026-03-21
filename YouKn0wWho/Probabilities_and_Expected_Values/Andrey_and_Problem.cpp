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
	int n; cin >> n;
	vector<ld> a(n);
	for(ld &i : a) cin >> i;
	sort(a.begin(),a.end(),greater<ld>());
	vector<vector<ld>> dp(n+1,vector<ld>(n+1,0));
	dp[0][1] = 1;
	for(ld p : a){
		for(int i = n; i > 0; i--){
			ld pi = 1.0 - p;
			if(dp[i][i] < dp[i-1][i-1]*pi + dp[i-1][i]*p){
				dp[i][i] = dp[i-1][i-1]*pi + dp[i-1][i]*p;
				if(i != n) dp[i][i+1] = dp[i-1][i]*pi;
			}
		}
	}
	ld ans = 0;
	cout << fixed << setprecision(12);
	// for(int i = 0; i <= n; i++){
	// 	for(int j = 0; j <= n; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for(int i = 1; i <= n; i++){
		ans = max(ans, dp[i][i]);
	}
	cout << ans << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

