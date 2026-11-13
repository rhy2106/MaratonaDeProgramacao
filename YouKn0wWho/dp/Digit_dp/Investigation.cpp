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
int k;

ll dp[20][100][100][2];

ll f(int pos, int mod, int soma, int tight){
	ll &ans = dp[pos][mod][soma][tight];
	if(ans != -1) return ans;
	ans = 0;
	if(pos == s.size()) 
		return ans = (mod%k || soma%k ? 0 : 1);
	int l = tight ? (s[pos] - '0') : 9;
	for(int i = 0; i <= l; i++){
		int nt = tight & (i == l);
		int nmod = (mod + i)%k;
		int nsoma = (soma*10 + i)%k;
		ans += f(pos+1, nmod, nsoma, nt);
	}
	return ans;
}

ll cnt( ll x ){
	s = to_string(x);
	memset(dp,-1,sizeof(dp));
	return f(0, 0, 0, 1);
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){ 
		ll l, r; cin >> l >> r >> k;
			cout << "Case " << t << ": " << (k > 90 ? 0 : (cnt(r) - cnt(l-1)) ) << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

