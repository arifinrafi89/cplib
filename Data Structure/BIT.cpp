// input vector 0 indexed, tree 1 indexed
#define ll long long

class BIT{
private:
 
    ll n;
    vector<ll> tree;
 
    ll lsb(ll idx){
        return (idx & -idx);
    }
 
    ll sum(ll idx){
        ll sum = 0;
        while(idx > 0){
            sum += tree[idx];
            idx -= lsb(idx);
        }
        return sum;
    }
 
public:
 
    BIT(vector<ll> &v){
        n = v.size();
        tree.assign(n + 1, 0);       
        for(ll i = 1; i <= n; i++){
            update(i, v[i - 1]); 
        }
    }
 
    void update(ll idx, ll val){
        while(idx <= n){
            tree[idx] += val;
            idx += lsb(idx);
        }
    }
 
    ll query(ll l, ll r){
        ll rangeSum = sum(r) - sum(l - 1);
        return rangeSum;
    }
 
};


