#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define lld long double
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
 
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif
 
void _print(ll t){cerr << t;}
void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(char t){cerr << t;}
void _print(double t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
 
template<class T, class V> void _print(pair<T, V> p){cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}";}
template<class T> void _print(vector<T> v){cerr << "[ "; for(auto i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> v){cerr << "[ "; for(auto i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(multiset<T> v){cerr << "[ "; for(auto i : v){_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(map<T, V> v){cerr << "[ "; for(auto i : v){_print(i); cerr << " ";} cerr << "]";}
 
const ll INF = 1e18;
const int MOD = 1e9 + 7;



void solve() {
    
}

 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        //cout << "Case " << i << ": ";
        //cout << '\n';
        solve();
    }
}