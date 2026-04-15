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
	ll fat[16];
	fat[0] = 1;
	for(int i = 1; i < 16; i++)
		fat[i] = fat[i-1]*i;
	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		int ans = INF;
		for(int mask = 0; mask < (1<<16); mask++){
			ll total = 0;
			int cnt = 0;
			for(int i = 0; i < 16; i++)
				if(mask & (1<<i)) total += fat[i], cnt++;
			if( n - total < 0 ) continue;
			ans = min( ans, cnt + __builtin_popcountll(n-total));
		}
		cout << ans << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

