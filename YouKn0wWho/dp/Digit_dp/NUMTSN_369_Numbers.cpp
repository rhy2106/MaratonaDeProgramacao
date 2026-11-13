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
int dp[51][17][17][17][2];

int f(int pos, int tres, int meia, int nove, int tight){
	if(tres >= 17) return 0;
	if(meia >= 17) return 0;
	if(nove >= 17) return 0;
	int total = max(tres,max(meia,nove));
	if(3*total-(tres+meia+nove) > s.size() - pos) return 0;
	if(pos == s.size()) return (tres == meia && tres == nove && tres > 0 ? 1 : 0);
	int &ans = dp[pos][tres][meia][nove][tight];
	if(ans != -1) return ans;
	ans = 0;
	int limit = (tight ? s[pos]-'0' : 9);
	for(int i = 0; i <= limit; i++){
		int nt = tight & (i == limit);
		int ntres = tres + (i == 3 ? 1 : 0);
		int nmeia = meia + (i == 6 ? 1 : 0);
		int nnove = nove + (i == 9 ? 1 : 0);
		ans = (ans + f(pos+1,ntres,nmeia,nnove,nt) ) % MOD;
	}
	return ans;
}

int cnt(string x){
	s = x;
	memset(dp,-1,sizeof(dp));
	return f(0,0,0,0,1);
}

string sub(string x){
	int i = x.size()-1;
	while(x[i] == '0' && i > 0) x[i] = '9',i--;
	x[i]--;
	return x;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		string l, r; cin >> l >> r;
		cout << (cnt(r) - cnt(sub(l)) + MOD) % MOD << endl;
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

