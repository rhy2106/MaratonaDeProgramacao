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

ll phi(ll n){
	ll ans = n;
	for(ll i = 2; i*i <= n; i++){
		if( n % i == 0 ){
			while( n % i == 0 ) n /= i;
			ans -= ans / i;
		}
	}
	if( n > 1 ) ans -= ans / n;
	return ans;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;

	int tt; cin >> tt;
	for(int z = 1; z <= tt; z++){
		cout << "Case " << z << endl;
		ll n, q; cin >> n >> q;
		vector<ll> divisores;
		vector<ll> prefix;
		ll phi_n = phi(n); // 1e6
		for(ll i = 1; i*i <= n; i++){ // 1e7
			if(n % i != 0) continue;
			divisores.pb(i);
			if( n / i != i) divisores.pb(n/i);
		}
		sort(divisores.begin(),divisores.end());
		for(ll i : divisores)
			prefix.pb(phi(n / i));

		for(int i = 1; i < prefix.size(); i++)
			prefix[i] += prefix[i-1];
		while(q--){ // 5e5
			ll k; cin >> k;
			int i = upper_bound(divisores.begin(),divisores.end(),k) - divisores.begin();
			i--;
			cout << ( i >= 0 ? prefix[i] : 0 ) << endl;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

