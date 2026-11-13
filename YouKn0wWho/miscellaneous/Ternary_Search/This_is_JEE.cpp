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

double f(double b, double c, double x){
	return (x*x + b*x + c) / sin(x);
}

void solve(){
	double b, c; cin >> b >> c;

	double l = 0, r = PI/2.0;
	while( r - l > eps ){
		double m1 = l + (r - l) / 3.0;
		double m2 = r - (r - l) / 3.0;
		double f1 = f(b,c,m1);
		double f2 = f(b,c,m2);
		if( f1 > f2) l = m1;
		else r = m2;
	}
	cout << fixed << setprecision(6);
	cout << f(b,c,l) << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	cin >> tt;
	while(tt--) solve();
    return 0;
}

