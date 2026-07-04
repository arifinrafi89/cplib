// 0 indexed, no lazy
#define ll long long

class SegmentTree2D {
private:
    ll n, m;
    vector<vector<ll>> tree;

    void buildY(ll nodeX, ll startX, ll endX, ll nodeY, ll startY, ll endY, vector<vector<ll>> &v) {
        if (startY == endY) {
            if (startX == endX) {
                tree[nodeX][nodeY] = v[startX][startY];
            }
            else {
                tree[nodeX][nodeY] = tree[nodeX * 2 + 1][nodeY] + tree[nodeX * 2 + 2][nodeY];
            }
        }
        else {
            ll mid = startY + (endY - startY) / 2;
            buildY(nodeX, startX, endX, nodeY * 2 + 1, startY, mid, v);
            buildY(nodeX, startX, endX, nodeY * 2 + 2, mid + 1, endY, v);
            tree[nodeX][nodeY] = tree[nodeX][nodeY * 2 + 1] + tree[nodeX][nodeY * 2 + 2];
        }
        return;
    }

    void buildX(ll nodeX, ll startX, ll endX, vector<vector<ll>> &v) {
        if (startX != endX) {
            ll mid = startX + (endX - startX) / 2;
            buildX(nodeX * 2 + 1, startX, mid, v);
            buildX(nodeX * 2 + 2, mid + 1, endX, v);
        }
        buildY(nodeX, startX, endX, 0, 0, m - 1, v);
        return;
    }

    void updateY(ll nodeX, ll startX, ll endX, ll nodeY, ll startY, ll endY, ll x, ll y, ll val) {
        if (startY == endY) {
            if (startX == endX) {
                tree[nodeX][nodeY] += val;
            }
            else {
                tree[nodeX][nodeY] = tree[nodeX * 2 + 1][nodeY] + tree[nodeX * 2 + 2][nodeY];
            }
        }
        else {
            ll mid = startY + (endY - startY) / 2;
            if (y <= mid) {
                updateY(nodeX, startX, endX, nodeY * 2 + 1, startY, mid, x, y, val);
            }
            else {
                updateY(nodeX, startX, endX, nodeY * 2 + 2, mid + 1, endY, x, y, val);
            }
            tree[nodeX][nodeY] = tree[nodeX][nodeY * 2 + 1] + tree[nodeX][nodeY * 2 + 2];
        }
        return;
    }

    void updateX(ll nodeX, ll startX, ll endX, ll x, ll y, ll val) {
        if (startX != endX) {
            ll mid = startX + (endX - startX) / 2;
            if (x <= mid) {
                updateX(nodeX * 2 + 1, startX, mid, x, y, val);
            }
            else {
                updateX(nodeX * 2 + 2, mid + 1, endX, x, y, val);
            }
        }
        updateY(nodeX, startX, endX, 0, 0, m - 1, x, y, val);
        return;
    }

    ll queryY(ll nodeX, ll nodeY, ll startY, ll endY, ll y1, ll y2) {
        if (y2 < startY || y1 > endY) {
            return 0;
        }
        if (y1 <= startY && endY <= y2) {
            return tree[nodeX][nodeY];
        }
        ll mid = startY + (endY - startY) / 2;
        ll q1 = queryY(nodeX, nodeY * 2 + 1, startY, mid, y1, y2);
        ll q2 = queryY(nodeX, nodeY * 2 + 2, mid + 1, endY, y1, y2);
        return q1 + q2;
    }

    ll queryX(ll nodeX, ll startX, ll endX, ll x1, ll x2, ll y1, ll y2) {
        if (x2 < startX || x1 > endX) {
            return 0;
        }
        if (x1 <= startX && endX <= x2) {
            return queryY(nodeX, 0, 0, m - 1, y1, y2);
        }
        ll mid = startX + (endX - startX) / 2;
        ll q1 = queryX(nodeX * 2 + 1, startX, mid, x1, x2, y1, y2);
        ll q2 = queryX(nodeX * 2 + 2, mid + 1, endX, x1, x2, y1, y2);
        return q1 + q2;
    }

public:
    SegmentTree2D(vector<vector<ll>> &mat) {
        n = mat.size();
        m = mat[0].size();
        tree.resize(4 * n, vector<ll>(4 * m));
        buildX(0, 0, n - 1, mat);
        return;
    }

    void update(ll x, ll y, ll val) {
        updateX(0, 0, n - 1, x, y, val);
        return;
    }

    ll query(ll x1, ll y1, ll x2, ll y2) {
        return queryX(0, 0, n - 1, x1, x2, y1, y2);
    }
};
