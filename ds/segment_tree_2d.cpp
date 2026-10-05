// 0-indexed, point update, rectangle query [x1, x2] x [y1, y2] (x = row, y = column)
// to customize: change node, E (identity) and merge (must be commutative)
struct node {
    ll val;
};
node E = {0};
node merge(node a, node b) {
    return {a.val + b.val};
}

struct segment_tree_2d {
    int n, m;
    vector<vector<node>> t;

    segment_tree_2d(int n, int m) : n(n), m(m), t(4 * n, vector<node>(4 * m, E)) {}

    void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int y, node val) {
        if (ly == ry) {
            if (lx == rx) t[vx][vy] = val;
            else t[vx][vy] = merge(t[2 * vx][vy], t[2 * vx + 1][vy]);
            return;
        }
        int my = (ly + ry) / 2;
        if (y <= my) update_y(vx, lx, rx, 2 * vy, ly, my, y, val);
        else update_y(vx, lx, rx, 2 * vy + 1, my + 1, ry, y, val);
        t[vx][vy] = merge(t[vx][2 * vy], t[vx][2 * vy + 1]);
    }

    void update_x(int vx, int lx, int rx, int x, int y, node val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) update_x(2 * vx, lx, mx, x, y, val);
            else update_x(2 * vx + 1, mx + 1, rx, x, y, val);
        }
        update_y(vx, lx, rx, 1, 0, m - 1, y, val);
    }

    node query_y(int vx, int vy, int ly, int ry, int y1, int y2) {
        if (y2 < ly || ry < y1) return E;
        if (y1 <= ly && ry <= y2) return t[vx][vy];
        int my = (ly + ry) / 2;
        return merge(query_y(vx, 2 * vy, ly, my, y1, y2), query_y(vx, 2 * vy + 1, my + 1, ry, y1, y2));
    }

    node query_x(int vx, int lx, int rx, int x1, int x2, int y1, int y2) {
        if (x2 < lx || rx < x1) return E;
        if (x1 <= lx && rx <= x2) return query_y(vx, 1, 0, m - 1, y1, y2);
        int mx = (lx + rx) / 2;
        return merge(query_x(2 * vx, lx, mx, x1, x2, y1, y2), query_x(2 * vx + 1, mx + 1, rx, x1, x2, y1, y2));
    }

    void update(int x, int y, node val) { update_x(1, 0, n - 1, x, y, val); }
    node query(int x1, int y1, int x2, int y2) { return query_x(1, 0, n - 1, x1, x2, y1, y2); }
};
