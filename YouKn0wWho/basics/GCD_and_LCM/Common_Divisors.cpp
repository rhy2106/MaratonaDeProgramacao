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

ll gcd(ll a, ll b){
	while( b > 0 ){
		ll c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	ll a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	ll num = a[0];
	for(int i = 0; i < n; i++) num = gcd(num,a[i]);
	ll ans = 0;
	for(ll i = 1; i*i <= num; i++){
		if(num % i) continue;
		ans++;
		if( num / i != i ) ans++;
	}
	cout << ans << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

