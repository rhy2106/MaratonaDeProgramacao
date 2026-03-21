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

int f(int x){
	int r = 0;
	while(x > 0){
		r += x % 10;
		x /= 10;
	}
	return r;
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int tt; cin >> tt;
	while(tt--){
		string s; cin >> s;
		int n = s.size();
		if(n == 1){
			cout << s << endl;
			continue;
		}
		vector<int> cnt(10);
		int dsum = 0;
		for(char c : s){
			cnt[c - '0']++;
			dsum += c - '0';
		}
		for(int i = 1; i <= 9*n; i++){
			int x = i;
			string ns = "";
			while(x > 9){
				ns += to_string(x);
				x = f(x);
			}
			ns += to_string(x);
			vector<int> xcnt(10);
			int xsum = 0;
			for(char c : ns){
				xcnt[c -'0']++;
				xsum += c - '0';
			}
			int erro = 0;
			for(int j = 0; j < 10; j++)
				if(xcnt[j] > cnt[j]) erro++;
			if(dsum - xsum != i)  erro++;
			if(erro) continue;
			string res = "";
			for(int j = 9; j >= 0; j--)
				for(int k = 0; k < cnt[j]-xcnt[j]; k++)
					res.push_back('0' + j);
			res += ns;
			cout << res << endl;
			break;
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

