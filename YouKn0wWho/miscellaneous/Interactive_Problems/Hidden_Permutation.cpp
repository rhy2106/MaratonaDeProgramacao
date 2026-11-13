#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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
const ld eps = 1e-9;
const ld PI = 3.14159265359;

using namespace std;

bool f(int i, int j){
	cout << "? " << i << " " << j << endl;
	cout.flush();
	string ans; cin >> ans;
	return ans == "YES";
}

void solve(){
	int n; cin >> n;
	vector<int> idx(n+1);
	for(int i = 1; i <= n; i++) idx[i] = i;
	stable_sort(idx.begin()+1,idx.end(), f);
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
		a[idx[i]] = i;
	cout << "! ";
	for(int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	while(tt--) solve();
    return 0;
}

