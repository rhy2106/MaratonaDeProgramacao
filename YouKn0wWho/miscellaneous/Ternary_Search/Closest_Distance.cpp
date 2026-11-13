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
#define iPair pair<double,double>
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

ld dist(iPair p1, iPair p2){
	return sqrt(pow(p2.f - p1.f, 2) + pow(p2.s - p1.s, 2));
}

ld f(iPair a, iPair b, iPair c, iPair d, ld p){
	iPair p1 = {a.f + (b.f-a.f)*p, a.s + (b.s-a.s)*p};
	iPair p2 = {c.f + (d.f-c.f)*p, c.s + (d.s-c.s)*p};

	return dist(p1,p2);
}

void solve(int testCase){
	cout << "Case " << testCase + 1 << ": ";
	iPair a, b, c, d;
	cin >> a.f >> a.s;
	cin >> b.f >> b.s;
	cin >> c.f >> c.s;
	cin >> d.f >> d.s;

	ld l = 0, r = 1;
	while( r - l > 1e-15){
		ld m1 = l + (r-l)/3;
		ld m2 = r - (r-l)/3;
		ld f1 = f(a,b,c,d,m1);
		ld f2 = f(a,b,c,d,m2);
		if(f1 > f2) l = m1;
		else r = m2;
	}

	cout << fixed << setprecision(6);
	cout << f(a,b,c,d,l) << endl;
}

int main(){
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    fastio;
	int tt = 1;
	cin >> tt;
	for(int i = 0; i < tt; i++) solve(i);
    return 0;
}

