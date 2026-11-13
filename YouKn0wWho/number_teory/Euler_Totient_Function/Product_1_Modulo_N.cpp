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
int ok[MAXN];

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	ll prod = 1;
	memset(ok,0,sizeof(ok));
	for(int i = 1; i < n; i++){
		if(gcd(i,n) != 1) continue;
		ok[i] = 1;
		prod = (prod*i) % n;
	}
	if(prod != 1) ok[prod] = 0;
	int cnt = 0;
	for(int i = 1; i < n; i++)
		if( ok[i] ) cnt++;
	cout << cnt << endl;
	for(int i = 1; i < n; i++)
		if( ok[i] ) cout << i << " ";
	cout << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

