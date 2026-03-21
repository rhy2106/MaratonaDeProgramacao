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

vector<vector<int>> grafo;
vector<ld> a;

struct No{
	int rotulo, i, pai;
	ld p;
	No(int rotulo, int i, int pai, ld p){
		this->p = p;
		this->rotulo = rotulo;
		this->i = i;
		this->pai = pai;
	}
};
ld dfs(){
	stack<No> q;
	q.push(No(0,0,-1,1.0));
	while(!q.empty()){
		No cur = q.top();
		q.pop();
		ld total = grafo[cur.rotulo].size() - (cur.rotulo == 0 ? 0 : 1);
		// cout << cur.rotulo << " " << cur.i << " " << cur.pai << " " << cur.p << endl;
		if(total == 0) a[0] += (ld)cur.i * cur.p;
		for(int v : grafo[cur.rotulo]){
			if(v == cur.pai) continue;
			ld prob = (ld)(cur.p * (1.0/total));
			// cout << prob << " " << total << endl;
			q.push( No( v ,cur.i+1 ,cur.rotulo ,prob ) );
		}
	}
	return a[0];
}

int main(){
    clock_t tinicio, tfim;
    tinicio = clock();
	// freopen("closing.in", "r", stdin);
	// freopen("closing.out", "w", stdout);
    _;
	int n; cin >> n;
	grafo.assign(n,vector<int>());
	a.assign(n,0);
	for(int i = 0; i< n-1; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		grafo[x].pb(y);
		grafo[y].pb(x);
	}
	cout << fixed << setprecision(12);
	cout << dfs() << endl;

	tfim = clock();
    cerr << (double)(tfim-tinicio)/CLOCKS_PER_SEC <<  " segundos" << endl;
    return 0;
}

