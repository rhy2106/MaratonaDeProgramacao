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
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
    _;
	int n; cin >> n;
	int a[n]; a[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = (a[i] + a[i-1]) % 7;
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i; j <= n; j++)
			if((a[j] - a[i]) % 7 == 0) ans = max(ans, j - i);
	cout << ans << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

