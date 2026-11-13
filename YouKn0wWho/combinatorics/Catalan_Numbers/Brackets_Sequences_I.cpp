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

ll fastexp(ll b, ll e){
	ll r = 1;
	while( e > 0 ){
		if(e & 1) r = (r*b) % MOD;
		b = (b*b) % MOD;
		e >>= 1;
	}
	return r;
}

ll modinv( ll x ){
	return fastexp( x, MOD-2 );
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	if(n&1 == 1){
		cout << 0 << endl;
		return 0;
	}
	int m = n/2;
	if( m == 0 ){
		cout << 1 << endl;
		return 0;
	}
	ll num = 1, den = 1;
	for(int i = m+2; i <= 2*m; i++) // (2m)! / (m+1)!
		num = (num*i)%MOD;
	for(int i = 1; i <= m; i++) // m!
		den = (den*i)%MOD;

	ll total = ( num * modinv(den) ) % MOD; // (2m)! / ( (m+1)! * m! )
	cout << total << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

