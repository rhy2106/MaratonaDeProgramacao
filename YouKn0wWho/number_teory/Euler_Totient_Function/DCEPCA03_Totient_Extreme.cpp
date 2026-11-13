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
const int MAXN = 1e4 + 5;
int phi[MAXN], prefix[MAXN];

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	for(int i = 0; i < MAXN; i++) phi[i] = i;
	for(int i = 2; i < MAXN; i++){
		if(phi[i] != i) continue;
		for(int j = i; j < MAXN; j += i)
			phi[j] -= phi[j] / i;
	}
	prefix[0] = 0;
	for(int i = 1; i < MAXN; i++)
		prefix[i] = phi[i] + prefix[i-1];

	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		cout << (ll) prefix[n] * prefix[n] << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

