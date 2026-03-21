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
	int r, s, p; cin >> r >> s >> p;
	ld dp[r+5][s+5][p+5];
	memset(dp,0,sizeof(dp));
	dp[r][s][p] = 1.0;
	for(int i = p; i >= 0; i--){
		for(int j = s; j >= 0; j--){
			for(int k = r; k >= 0; k--){
				ld total = k*i + j*i + k*j;
				if(k-1 >= 0 && total > 0) dp[k-1][j][i] += dp[k][j][i] * (ld)(k*i)/total;
				if(j-1 >= 0 && total > 0) dp[k][j-1][i] += dp[k][j][i] * (ld)(j*k)/total;
				if(i-1 >= 0 && total > 0) dp[k][j][i-1] += dp[k][j][i] * (ld)(j*i)/total;
			}
		}
	}

	ld ansp = 0;
	ld anss = 0;
	ld ansr = 0;
	for(int i = 0; i <= p; i++) ansp += dp[0][0][i];
	for(int i = 0; i <= s; i++) anss += dp[0][i][0];
	for(int i = 0; i <= r; i++) ansr += dp[i][0][0];
	cout << fixed << setprecision(12);
	cout << ansr << " " << anss << " " << ansp << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

