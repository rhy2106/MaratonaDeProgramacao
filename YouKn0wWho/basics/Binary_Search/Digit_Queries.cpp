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

ll fastpow(ll b, ll e){
	ll r = 1;
	while(e > 0){
		if(e&1) r = r * b;
		b = b * b;
		e >>= 1;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	vector<ll> b;
	ll total = 0;
	int j = 0;
	while(true){
		int d = 0, y = j*9;
		while(y > 0) d++, y /= 10;
		if(y + j-1 >= 17) break;
		ull x = 1ll * j * 9 * fastpow(10,j-1);
		total += x;
		b.pb(total);
		j++;
	}
	int tt; cin >> tt;

	while(tt--){
		ll n; cin >> n;
		ll total = 0;
		int l = 0, r = b.size();
		while(r - l > 1){
			int mid = (l + r) / 2;
			(n < b[mid] ? r : l) = mid;
		}
		// cout << n << " " << b[l] <<  endl;
		n -= b[l];
		// cout << n << " " << r << endl;
		ll x = fastpow(10,l) - 1 + n / r + ( n % r > 0 ? 1 : 0);
		// cout << x <<endl;
		ll d = n % r;
		if( d > 0 ) for(int i = 0; i < r-d; i++) x /= 10;
		cout << x % 10 << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

