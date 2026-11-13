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

ld f(const vector<ld>& a, ld x) {
    ld maxSum = 0;
    ld minSum = 0;

    ld curMax = 0;
    ld curMin = 0;

    for (ld v : a) {
        ld y = v - x;

        curMax = max(y, curMax + y);
        maxSum = max(maxSum, curMax);

        curMin = min(y, curMin + y);
        minSum = min(minSum, curMin);
    }

    return max(maxSum, -minSum);
}

void solve(){
	int n; cin >> n;
	vector<ld> a(n);
	for(ld &i : a) cin >> i;

	ld l = -10001, r = 10001;
	while( r - l > 1e-15 ){
		ld m1 = l + (r - l) / 3.0;
		ld m2 = r - (r - l) / 3.0;
		ld f1 = f(a,m1);
		ld f2 = f(a,m2);
		if( f1 > f2 ) l = m1;
		else r = m2;
	}
	cout << fixed << setprecision(9);
	cout << f(a,l) << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	// cin >> tt;
	while(tt--) solve();
    return 0;
}

