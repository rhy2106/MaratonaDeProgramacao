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
void swap( int& x, int& y ){
	int a = (x + y + abs(x-y))/2;
	int b = (x + y - abs(x-y))/2;
	x = a; y = b;
	return;
}

int main(){
    _;
	int a, b, c;
	cin >> a >> b >> c;
	int maior = a, meio = b, menor = c;
	swap(maior,meio);
	swap(maior,menor);
	swap(meio,menor);
	cout << menor << endl;
	cout << meio << endl;
	cout << maior << endl;
	cout << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

    return 0;
}

