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
const ull MOD = 1e9 + 7;
const ll A = 911382323;
const ll B = 972663749;

using namespace std;

ull fastexp(ull b, ull e){
	ull r = 1;
	while(e > 0){
		if(e&1) r = (r*b) % MOD;
		b = (b*b) % MOD;
		e >>= 1;
	}
	return r % MOD;
}

ull inv(ull x){
	return fastexp(x, MOD-2);
}

ull inve(ull x){
	return fastexp(x, MOD-3);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ull n; cin >> n;
	ull a[n];
	ull b[n];

	for(ull i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	ull cnt = 1;
	for(ull i = 0; i < n; i++)
		cnt = (cnt * (b[i]+1)) % MOD;
		

	ull soma = 1;
	for(ull i = 0; i < n; i++){
		ull x = fastexp(a[i], b[i]);
		ull num = (x - 1ull + MOD) % MOD;
		ull num2 = (num*inv(a[i] - 1ull) + x) % MOD;
		soma = (soma * num2) % MOD;
	}


	ull mul = 1;
	ull ecnt = 1;
	ull EXPMOD = MOD - 1;
	bool even = true;
	for(int i = 0; i < n; i++){
		ecnt = (ecnt * (b[i]+1)) % (MOD-1);
		if(b[i] % 2) even = false;
	}

	if(even){
		for(int i = 0; i < n; i++){
			ull e = ecnt % EXPMOD;
			e = (b[i]/2 * e) % EXPMOD;
			mul = (mul * fastexp(a[i],e)) % MOD;
		}

	} else{
		for(int i = 0; i < n; i++){
			ull e = ((ecnt)*inve(2)) % EXPMOD;
			e = (b[i] * e) % EXPMOD;
			mul = (mul * fastexp(a[i],e)) % MOD;
		}
	}

	cout << cnt << " " << soma << " " << mul << endl;;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}
