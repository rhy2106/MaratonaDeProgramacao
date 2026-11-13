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

const int MAXN = 1e5 + 5;
ll phi[MAXN], ans[MAXN];

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

	ans[0] = 0;
	for(int i = 1; i < MAXN; i++)
		ans[i] = i - phi[i] + ans[i-1];

	int tt; cin >> tt;
	for(int t = 1; t <= tt; t++){
		int n; cin >> n;
		cout << "Case " << t << ": " << ans[n] << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

