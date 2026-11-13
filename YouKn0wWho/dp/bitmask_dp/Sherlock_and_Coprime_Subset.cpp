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
	vector<int> primos;
	vector<int> masks(51,0);
	for(int i = 2; i <= 50; i++){
		if(masks[i]) continue;
		primos.pb(i);
		for(int j = i; j <= 50; j+=i){
			masks[j] |= (1<<(primos.size()-1));
		}
	}
	int m = primos.size();
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		vector<int> b;
		vector<int> dp((1<<m),0);
		int ums = 0;
		// como 1 pode ser valido para qualquer subset,
		// ele pode ser contado fora da dp e somado no final
		// Alem disso, caso ele estivesse dentro da dp,
		// ele causaria contagem duplicada de subsets,
		// exatamente por ser valido para qualquer um
		for(int i = 0; i < n; i++){
			if(a[i] == 1){
				ums++;
				continue;
			}
			b.pb(masks[a[i]]);
			dp[masks[a[i]]] = 1;
		}

		for(int i = 0; i < b.size(); i++){
			for(int mask = 1; mask < (1<<m); mask++){
				if(mask & b[i]) continue;
				if(dp[mask] == 0) continue;
				int nmask = mask | b[i];
				dp[nmask] = max( dp[mask] + dp[b[i]], dp[nmask] );
				bitset<15> tmp2(nmask);
			}
		}
		int ans = 0;
		for(int mask = 0; mask < (1<<m); mask++)
			ans = max(ans,dp[mask]+ums);
		cout << ans << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

