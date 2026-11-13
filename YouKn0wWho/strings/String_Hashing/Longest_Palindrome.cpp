#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ull unsigned long long
#define ll long long
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
const ll MOD = 972663749;

using namespace std;

vector<ll> h1, h2, p;
ll A = 911382323;

ll getHash(vector<ll>& h,int l, int r){
	ll x = (h[r+1] - (h[l]*p[r-l+1] % MOD) + MOD) % MOD;
	return x;
}

string ver(string s, ll x){
	int n = s.size();
	for(int r = 0; r <= n-x; r++){
		int l = r + x - 1;
		if(getHash(h1, r, l) == getHash(h2,n-1-l, n-1-r)) return s.substr(r,x);
	}
	return "";
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	string s; cin >> s;
	int n = s.size();
	h1.assign(n+1,0);
	h2.assign(n+1,0);
	p.assign(n+1,0);
	p[0] = 1;
	string s2 = s;
	reverse(s2.begin(),s2.end());
	for(int i = 0; i < n; i++){
		h1[i+1] = (h1[i]*A + (s[i]-'a')) % MOD;
		h2[i+1] = (h2[i]*A + (s2[i]-'a')) % MOD;
		p[i+1] = (p[i]*A) % MOD;
	}
	int r = 0, l = (s.size()+1)/2;
	string ans = "";
	while( r + 1 < l){
		int m = (r+l)/2;
		m *= 2;
		ans = ver(s,m);
		if(ans.size()) r = m/2;
		else l = m/2;
	}
	ans = ver(s,r*2);
	string ans2 = "";
	r = 0; l = (s.size()+1)/2;
	while( r + 1 < l){
		int m = (r+l)/2;
		m = m*2 + 1;
		ans2 = ver(s,m);
		if(ans2.size()) r = (m-1)/2;
		else l = (m-1)/2;
	}
	ans2 = ver(s,r*2 + 1);
	if(ans.size() < ans2.size()) ans = ans2;
	string ans3 = ver(s,s.size());
	if(ans3.size()) ans = ans3;
	cout << ans << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

