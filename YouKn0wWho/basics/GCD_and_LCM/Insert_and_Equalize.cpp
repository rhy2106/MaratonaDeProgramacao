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
	while(b > 0){
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
	int tt; cin >> tt;
	while(tt--){
		ll n; cin >> n;
		ll a[n];
		for(ll &i : a) cin >> i;
		ll g = 0;
		ll soma = 0;
		sort(a, a + n);
		for(int i = 0; i < n-1; i++) g = gcd(g,a[i+1]-a[i]);
		for(int i = 0; i < n; i++) soma += a[i];
		g = max(g,1ll);
		ll res = a[n-1];
		int j = n-1;
		while(true){
			while(j >= 0 && a[j] > res) j--;
			if(j < 0 || a[j] != res) break;
			res -= g;
		}
		cout << (a[n-1]*(n+1) - (soma + res)) / g << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

