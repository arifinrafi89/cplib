// integer geometry, ll coordinates (cross products stay exact up to ~1e9 coordinates)
struct pt {
    ll x, y;
    pt operator-(pt o) const { return {x - o.x, y - o.y}; }
    bool operator<(pt o) const { return make_pair(x, y) < make_pair(o.x, o.y); }
    bool operator==(pt o) const { return x == o.x && y == o.y; }
};

ll cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
ll dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }

int orient(pt a, pt b, pt c) {   // 1 = left turn (ccw), -1 = right turn, 0 = collinear
    ll v = cross(b - a, c - a);
    return (v > 0) - (v < 0);
}

bool on_segment(pt a, pt b, pt p) {   // p on segment ab, endpoints included
    return orient(a, b, p) == 0 && dot(a - p, b - p) <= 0;
}

bool segments_intersect(pt a, pt b, pt c, pt d) {   // touching counts
    int o1 = orient(a, b, c), o2 = orient(a, b, d), o3 = orient(c, d, a), o4 = orient(c, d, b);
    if (o1 != o2 && o3 != o4) return true;
    return on_segment(a, b, c) || on_segment(a, b, d) || on_segment(c, d, a) || on_segment(c, d, b);
}

ll polygon_area2(const vector<pt> &p) {   // twice the area, positive if ccw
    ll s = 0;
    for (int i = 0; i < (int)p.size(); i++) s += cross(p[i], p[(i + 1) % p.size()]);
    return s;
}

int point_in_polygon(const vector<pt> &p, pt q) {   // any simple polygon: 0 outside, 1 boundary, 2 inside
    int n = p.size();
    bool in = false;
    for (int i = 0; i < n; i++) {
        pt a = p[i], b = p[(i + 1) % n];
        if (on_segment(a, b, q)) return 1;
        if ((a.y > q.y) != (b.y > q.y) && orient(a, b, q) * (b.y > a.y ? 1 : -1) > 0) in = !in;
    }
    return in ? 2 : 0;
}

vector<pt> convex_hull(vector<pt> p) {   // ccw, no collinear points
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    int n = p.size();
    if (n < 3) return p;
    vector<pt> h(2 * n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k >= 2 && orient(h[k - 2], h[k - 1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && orient(h[k - 2], h[k - 1], p[i]) <= 0) k--;
        h[k++] = p[i];
    }
    h.resize(k - 1);
    return h;
}
