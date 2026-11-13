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

int w, b;
map<iPair,ld> dp;

ld f(int white, int black){
	if(white <= 0) return 0;
	if(black <= 0) return 1;
	iPair a = mp(white,black);
	if(dp.count(a)) return dp[a];
	ld ans = 0;
	ld win = ( (ld)white / (ld)(white + black) ); // princesa vence
	ans += win; // princesa vence

	ld lose = ( (ld)black / (ld)(white + black) ); // princesa perde
	lose *= (ld)(black-1) / (ld)(white + black - 1); // dragao perde
	
	if( lose > 1e-13 ){
		ld pblack = (ld)(black-2) / (ld)(white + black - 2);
		ld pwhite = (ld)white / (ld)(white + black - 2);
		ans += lose * pwhite * f( white-1, black-2 );
		ans += lose * pblack * f( white,   black-3 );
	}

	return dp[a] = ans;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	cin >> w >> b;
	cout << fixed << setprecision(12);
	cout << f(w, b) << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

