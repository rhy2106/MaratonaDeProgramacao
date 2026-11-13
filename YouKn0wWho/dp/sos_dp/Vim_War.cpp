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

using namespace std;

ll fastexp(ll b, ll exp){
	ll r = 1;
	while( exp > 0 ){
		if(exp&1) r = (r * b) % MOD;
		b = (b * b) % MOD;
		exp /= 2;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
    // freopen("closing.in", "r", stdin);
    // freopen("closing.out", "w", stdout);
    _;
    int n, m; cin >> n >> m;
    vector<ll> freq(1 << m, 0);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int mask = 0;
        for(int j = 0; j < m; j++)
            if(s[j] == '1') mask |= (1<<j);
		freq[mask]++;
    }

    string s; cin >> s;
    int res = 0;
    for(int i = 0; i < m; i++)
        if(s[i] == '1') res |= (1<<i);

	for(int mask = 0; mask < (1<<m); mask++)
		if((mask | res) != res) freq[mask] = 0;

	for(int b = 0; b < m; b++){
		for(int mask = 0; mask < (1<<m); mask++){
			if(mask & (1<<b)){
				int nmask = mask ^ (1<<b);
				freq[mask] = (freq[nmask] + freq[mask]) % MOD;
			}
		}
	}
		
	ll ans = 0;

	for(int mask = res; ; mask = (mask-1) & res){
		int bits = __builtin_popcount(res^mask);
		ll ways = fastexp(2,freq[mask]);
		if(!(bits & 1))
			ans = (ans + ways) % MOD;
		else
			ans = (ans - ways + MOD) % MOD;
		if(mask == 0) break;
	}
	if(res == 0) ans--;
	cout << (ans  + MOD) % MOD << endl;
    tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}


