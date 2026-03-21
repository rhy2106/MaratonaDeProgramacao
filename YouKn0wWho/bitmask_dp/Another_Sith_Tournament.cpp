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

int n;
vector<vector<ld>> dp;
vector<vector<ld>> a;

ld solve(int mask, int i){
	ld& ans = dp[mask][i];
	if(ans > -0.5) return ans;
	if(mask == (1<<n)-1) return ans = !i;
	ans = 0;
	for(int j = 0; j < n; j++){
		if(mask & (1<<j)) continue;
		ld tmp = 0;
		tmp += solve(mask | (1<<j), i) * a[i][j];
		tmp += solve(mask | (1<<j), j) * a[j][i];
		ans = max(ans, tmp);
	}
	return ans;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	cin >> n;
	int m = (1<<n);
	a.assign(n,vector<ld>(n,0));
	dp.assign(m,vector<ld>(n,-1));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	ld ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			int mask = (1<<i) | (1<<j);
			ld tmp = 0;
			tmp += solve(mask,i) * a[i][j];
			tmp += solve(mask,j) * a[j][i];
			ans = max(ans, tmp);
		}
	}

	cout << fixed << setprecision(9) << ans << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

