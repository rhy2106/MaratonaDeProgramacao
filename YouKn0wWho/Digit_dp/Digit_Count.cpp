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

int n;
int d[10];
ll dp[11][10];

ll f(int pos, int last){
	if( pos == n ) return 1;
	ll &ans = dp[pos][last];
	if( ans != -1 ) return ans;
	ans = 0;
	int l = (last == 0 ? 1 : max(last-2,1));
	int r = (last == 0 ? 9 : min(last+2,9));
	for(int i = l; i <= r; i++){
		if(!d[i]) continue;
		ans += f(pos + 1, i);
	}
	return ans;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		cout << "Case " << t << ": ";
		int m; cin >> m >> n;
		for(int i = 0; i < 10; i++) d[i] = 0;
		for(int i = 0; i < m; i++){
			int x; cin >> x;
			d[x]++;
		}
		memset(dp,-1,sizeof(dp));
		cout << f(0,0) << endl;
		
		
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

