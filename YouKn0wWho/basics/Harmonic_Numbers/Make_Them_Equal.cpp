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
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		char c; cin >> c;
		string s; cin >> s;
		if(s == string(n,c)) cout << 0 << endl << endl;
		else{
			bool yes = true;
			for(int i = n; i > 0; i--){
				yes = true;
				for(int j = i; j <= n; j+=i)
					if(s[j-1] != c) yes = false;
				if(yes){
					cout << 1 << endl;
					cout << i << endl;
					break;
				}
			}
			if(!yes){
				cout << 2 << endl;
				cout << n << " " << n-1 << endl;
			}
		}
	}
	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

