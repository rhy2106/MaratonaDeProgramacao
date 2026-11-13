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

const int MAXN = 2e5 + 5;
ll phi[MAXN];

ll gcd(ll a, ll b){
	while( b > 0 ){
		ll c = b;
		b = a % b;
		a = c;
	}
	return a;
}

ll lcm(ll x, ll y){
	return x / gcd(x,y) * y;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	for(int i = 0; i < MAXN; i++) phi[i] = i;
	for(int i = 2; i < MAXN; i++){
		if( phi[i] != i ) continue;
		for(int j = i; j < MAXN; j += i)
			phi[j] -= phi[j] / i;
	}

	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		ll a[n+1];
		map<ll,ll> b;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			b[lcm(phi[a[i]],i)]++;
		}

		ll total = 0;
		for(auto [key,val] : b)
			total += val * (val - 1) / 2;
		ll ans = total;
		for(int i = 1; i <= n; i++){
			ll tmp = total;
			ll x = lcm(phi[a[i]],i), y = lcm(phi[a[i]+1],i);
			if( x == y ) continue;
			tmp += (b[x] - 1) * (b[x] - 2) / 2 - b[x] * (b[x] - 1) / 2;
			tmp += (b[y] + 1) * b[y] / 2 - b[y] * (b[y] - 1) / 2;
			if( tmp > ans ) ans = tmp;
		}

		cout << ans << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

