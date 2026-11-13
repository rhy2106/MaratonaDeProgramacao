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
const ll MOD = 1e9 + 7;
const ll A = 911382323;
const ll B = 972663749;

using namespace std;

long double fastexp(long double b, int e){
	long double r = 1;
	while(e>0){
		if(e&1) r = r*b;
		b *= b;
		e >>= 1;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	long double fat[15];
	fat[0] = fat[1] = 1;
	for(int i = 2; i < 15; i++) fat[i] = fat[i-1]*i;
	string s1, s2;
	cin >> s1 >> s2;
	int a[2] = {0,0}, b[3] = {0,0,0};
	for(char c : s1){
		if( c == '-' ) a[0]++;
		else a[1]++;
	}
	for(char c : s2){
		if( c == '-' ) b[0]++;
		else if( c == '+' ) b[1]++;
		else b[2]++;
	}
	if(b[0] > a[0] || b[1] > a[1]) {
		cout << 0 << endl;
		return 0;
	}
	long double ans = (fat[b[2]] / (fat[a[0]-b[0]] * fat[a[1]-b[1]])) * fastexp(0.5,b[2]);

	cout << fixed << setprecision(9)<< ans << endl;
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

