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
	while(b != 0){
		int c = b;
		b = a % b;
		a = c;
	}
	return a;
}

ll lmc( ll a, ll b ){
	return a*b/gcd(a,b);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		ll a, b, c, m; cin >> a >> b >> c >> m;
		ll conta = (m / a)*6ll;
		ll contb = (m / b)*6ll;
		ll contc = (m / c)*6ll;
		ll contab = (m / lmc(a,b))*3ll;
		ll contac = (m / lmc(a,c))*3ll;
		ll contbc = (m / lmc(c,b))*3ll;
		ll contabc = (m / lmc(lmc(a,b),c))*2ll;

		conta -= contab;
		conta -= contac;

		contb -= contab;
		contb -= contbc;

		contc -= contac;
		contc -= contbc;

		conta += contabc;
		contb += contabc;
		contc += contabc;
		
		cout << conta << " " << contb << " " << contc << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

