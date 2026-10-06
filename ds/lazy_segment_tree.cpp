// 0-indexed, range add / assign, range query [l, r]
// to customize: change node, E (identity), merge and apply
//
// sum (default):  E = {0}         merge = {a.val + b.val}       apply = {a.val * f.mul + f.add * len}
// min:            E = {(ll)1e18}  merge = {min(a.val, b.val)}   apply = {a.val * f.mul + f.add}
// max:            E = {-(ll)1e18} merge = {max(a.val, b.val)}   apply = {a.val * f.mul + f.add}
struct node {
    ll val;
};
node E = {0};
node merge(node a, node b) {
    return {a.val + b.val};
}

struct tag {
    ll mul, add;
};
tag ID = {1, 0};
tag compose(tag f, tag g) {
    return {f.mul * g.mul, f.add * g.mul + g.add};
}
node apply(node a, tag f, int len) {
    return {a.val * f.mul + f.add * len};
}

struct lazy_segment_tree {
    int n;
    vector<node> t;
    vector<tag> lz;

    lazy_segment_tree(int n) : n(n), t(4 * n, E), lz(4 * n, ID) {}

    void push(int v, int tl, int tr) {
        if (lz[v].mul == 1 && lz[v].add == 0) return;
        int tm = (tl + tr) / 2;
        t[2 * v] = apply(t[2 * v], lz[v], tm - tl + 1);
        lz[2 * v] = compose(lz[2 * v], lz[v]);
        t[2 * v + 1] = apply(t[2 * v + 1], lz[v], tr - tm);
        lz[2 * v + 1] = compose(lz[2 * v + 1], lz[v]);
        lz[v] = ID;
    }

    void build(int v, int tl, int tr, vector<ll>& a) {
        if (tl == tr) { t[v] = {a[tl]}; return; }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm + 1, tr, a);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    void update(int v, int tl, int tr, int l, int r, tag f) {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r) {
            t[v] = apply(t[v], f, tr - tl + 1);
            lz[v] = compose(lz[v], f);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, r, f);
        update(2 * v + 1, tm + 1, tr, l, r, f);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    node query(int v, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return E;
        if (l <= tl && tr <= r) return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return merge(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

    void build(vector<ll>& a) { build(1, 0, n - 1, a); }
    void add(int l, int r, ll d) { update(1, 0, n - 1, l, r, {1, d}); }
    void assign(int l, int r, ll x) { update(1, 0, n - 1, l, r, {0, x}); }
    node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
