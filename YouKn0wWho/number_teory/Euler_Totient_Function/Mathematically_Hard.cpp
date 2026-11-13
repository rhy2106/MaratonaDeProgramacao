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

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int MAXN = 5e6 + 5;
	vector<ull> t(MAXN, 0);
	for(int i = 0; i < MAXN; i++) t[i] = i;
	for(int i = 2; i < MAXN; i++){
		if(t[i] != i) continue;
		for(int j = i; j < MAXN; j += i)
			t[j] -= t[j]/i;
	}
	for(int i = 1; i < MAXN; i++) t[i] = t[i-1] + t[i]*t[i];

	int tt; cin >> tt;
	for(int z = 1; z <= tt; z++){
		cout << "Case " << z << ": ";
		ull l, r; cin >> l >> r;
		ull score = (t[r] - t[l-1]);
		cout << score << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

