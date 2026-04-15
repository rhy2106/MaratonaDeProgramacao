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
	string s; cin >> s;
	int n = s.size();
	int a[n+1], b[n+1]; a[0] = b[0] = 0;
	for(int i = 0; i < s.size(); i++){
		a[i+1] = a[i];
		b[i+1] = b[i];
		if(s[i] == 'a') a[i+1]++;
		else b[i+1]++;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i; j <= n; j++)
			ans = max(ans, a[n] - a[j] + b[j] - b[i] + a[i]);
	cout << ans << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

