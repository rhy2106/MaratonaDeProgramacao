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
const ll MOD = 1e7 + 7;
const ll A = 911382323;
const ll B = 972663749;

using namespace std;

const int MAXN = 1e6 + 5;
int prime[MAXN];

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	vector<ll> primos;
	primos.pb(2);
	for(int i = 0; i < MAXN; i++) prime[i] = 0;
	for(int i = 3; i < MAXN; i+=2){
		if(prime[i]) continue;
		primos.pb(i);
		for(int j = i; j < MAXN; j+=2*i)
			prime[j]++;
	}

	int n;
	while(cin >> n, n != 0){

		ll ans = 1;
		for(ll p : primos){
			if(p > n) break;
			ll e = 0, x = n, cnt = p;
			while( x / cnt > 0 ){
				e += x/cnt;
				cnt *= p;
			}
			e = ((e+1) * (e+2) ) % MOD;
			ans = ( ans * e ) % MOD;
			ans = ( ans * 5000004 ) % MOD;
		}
		cout << ans << endl;

	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

