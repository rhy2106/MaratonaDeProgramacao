#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define endl '\n'

using namespace std;

ll phi(ll n){
	ll ans = n;
	for(ll i = 2; i*i <= n; i++){
		if( n % i != 0 ) continue;
		while( n % i == 0 ) n /= i;
		ans -= ans / i;
	}
	if( n > 1 ) ans -= ans / n;
	return ans;
}

int main(){
    _;
	ll n;
	while(cin >> n, n != 0){
		cout << ( n == 1 ? 0 : phi(n) ) << endl;
	}
    return 0;
}

