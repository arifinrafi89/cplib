#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...) {}
#endif
 
#define ll long long
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve() {
    
}
  
int main() {
    fast;
    ll tc = 1;
    //cin >> tc;
    for (ll i = 1; i <= tc; i++) {
        //cout << "Case " << i << ": ";
        //cout << '\n';
        solve();  
    }
    return 0;
 } 