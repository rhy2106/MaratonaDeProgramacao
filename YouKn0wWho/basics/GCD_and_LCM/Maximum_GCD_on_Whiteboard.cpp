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
		int n, k; cin >> n >> k;
		ll freq[n+1], prefix[n+1];
		memset(freq,0,sizeof(freq));
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			freq[x]++;
		}
		prefix[0] = 0;
		for(int i = 1; i <= n; i++)
			prefix[i] = prefix[i-1] + freq[i];
		ll ans = 1;
		for(int g = 1; g <= n; g++){
			int t = min(4*g-1, n);
			ll good = n-prefix[t];
			if(g   <= n) good += freq[g];
			if(g*2 <= n) good += freq[2*g];
			if(g*3 <= n) good += freq[3*g];
			if(good >= n-k) ans = g;
		}
		cout << ans << endl;

		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

