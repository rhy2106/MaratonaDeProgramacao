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
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
    _;
	int n, q; cin >> n >> q;
	int a[3][n+1];
	memset(a,0,sizeof(a));
	for(int i = 1; i <= n; i++){
		int x; cin >> x; x--;
		a[x][i]++;
		a[0][i] += a[0][i-1];
		a[1][i] += a[1][i-1];
		a[2][i] += a[2][i-1];
	}
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		cout << a[0][r] - a[0][l-1] << " ";
		cout << a[1][r] - a[1][l-1] << " ";
		cout << a[2][r] - a[2][l-1] << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

