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

string s;
ll m, d;
ll dp[2001][2000][2][3];

// 2e7
//
ll f(int pos, int soma, int tight, int par){
	ll &ans = dp[pos][soma][tight][par];
	if(ans != -1) return ans;
	ans = 0;
	if(pos == s.size())
		return ans = ( soma % m ? 0 : 1 );
	int l = tight ? ( s[pos] - '0' ) : 9;
	for(int i = 0; i <= l; i++){
		if(par == 0 && i == d) continue;
		if(par == 1 && i != d) continue;
		if(par == 2 && i == d && d != 0) continue;
		int nt = tight & (i == l);
		int nsoma = (soma*10 + i) % m;
		int npar = (par == 2 && i == 0) ? 2 : ((par+1)%2);
		ans = ( ans + f(pos+1, nsoma, nt, npar) ) % MOD;
	}
	return ans;
}

ll cnt( string x ){
	s = x;
	memset(dp,-1,sizeof(dp));
	return f(0,0,1, 2);
}

string sub(string x){
	int i = x.size()-1;
	while(x[i] == '0' && i > 0) x[i] = '9', i--;
	x[i] = x[i]-1;
	return x;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	cin >> m >> d;
	string l, r; cin >> l >> r;
	// cout << r << " "<< sub(l) <<endl;
	cout << (cnt(r) - cnt(sub(l)) + MOD) % MOD << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

