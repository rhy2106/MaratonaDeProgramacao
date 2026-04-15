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

bool ver(string s, string c){
	bool ans = true;
	int i = 0;
	while( i < s.size() && ans){
		if(s[i] != c[i%c.size()]) ans = false;
		i++;
	}
	return ans;
}

ll gcd(ll a, ll b){
	while(b > 0){
		ll c = b;
		b = a%b;
		a = c;
	}
	return a;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	ll tt; cin >> tt;
	while(tt--){
		string s, x, y; cin >> s >> x >> y;
		ll cx0 = 0, cx1 = 0, cy0 = 0, cy1 = 0;
		bool yes = false;
		for(char c : x) (c == '0' ? cx0++ : cx1++);
		for(char c : y) (c == '0' ? cy0++ : cy1++);
		if(cx0 == cy0) yes = true;
		else if(cx1 != cy1){
			ll c0 = (cx0 - cy0) * s.size();
			ll c1 = cx1 - cy1;
			ll i = -(c0/c1);

			if( i >= 0 && c0 % c1 == 0){
				ll g = gcd(s.size(), i);
				string u = s.substr(0,g);
				yes = ver(s,u);
			}
		}
		cout << (yes ? "Yes" : "No") << endl;
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

