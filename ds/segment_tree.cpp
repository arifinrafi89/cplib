// 0-indexed, point update, range query [l, r]
// to customize: change node, E (identity) and merge
struct node {
    ll val;
};
node E = {0};
node merge(node a, node b) {
    return {a.val + b.val};
}

struct segment_tree {
    int n;
    vector<node> t;

    segment_tree(int n) : n(n), t(4 * n, E) {}

    void update(int v, int tl, int tr, int i, node x) {
        if (tl == tr) { t[v] = x; return; }
        int tm = (tl + tr) / 2;
        if (i <= tm) update(2 * v, tl, tm, i, x);
        else update(2 * v + 1, tm + 1, tr, i, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    node query(int v, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return E;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return merge(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

    void update(int i, node x) { update(1, 0, n - 1, i, x); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
