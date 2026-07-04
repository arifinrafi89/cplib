// 0 indexed, no lazy
#define ll long long

class SegmentTreeLazy {

private:
    ll n;
    vector<ll> tree, lazy;

    void build(ll node, ll start, ll end, vector<ll> &v) {
        if (start == end) {
            tree[node] = v[start];
        } else {
            ll mid = start + (end - start) / 2;
            build(2 * node + 1, start, mid, v);
            build(2 * node + 2, mid + 1, end, v);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void push(ll node, ll start, ll end) {
        if (lazy[node] == 0) return;
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(ll node, ll start, ll end, ll l, ll r, ll val) {
        push(node, start, end);
        if (r < start || end < l) return;  
        if (l <= start && end <= r) {              
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        ll mid = start + (end - start) / 2;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) return 0; 
        push(node, start, end);
        if (l <= start && end <= r) return tree[node];  
        ll mid = start + (end - start) / 2;
        return query(2 * node + 1, start, mid, l, r)
             + query(2 * node + 2, mid + 1, end, l, r);
    }

public:
    SegmentTreeLazy(vector<ll> &v) {
        n = v.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(0, 0, n - 1, v);
    }

    void update(ll idx, ll val) {
        update(0, 0, n - 1, idx, idx, val);
    }

    void update(ll l, ll r, ll val) {
        update(0, 0, n - 1, l, r, val);
    }

    ll query(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }
};
