// pairs (a, b): largest_second(k) = original index of the pair with the largest b among pairs with a <= k, or -1
vector<array<ll, 3>> ls_pts;   // {a, b, original index}, sorted
vector<int> ls_best;           // ls_best[i] = position in ls_pts of the largest b among ls_pts[0..i]

void build_largest_second(vector<pair<ll, ll>> v) {
    ls_pts.clear();
    for (int i = 0; i < (int)v.size(); i++) ls_pts.push_back({v[i].first, v[i].second, i});
    sort(ls_pts.begin(), ls_pts.end());
    ls_best.assign(ls_pts.size(), 0);
    for (int i = 1; i < (int)ls_pts.size(); i++)
        ls_best[i] = ls_pts[i][1] > ls_pts[ls_best[i - 1]][1] ? i : ls_best[i - 1];
}

int largest_second(ll k) {
    int i = upper_bound(ls_pts.begin(), ls_pts.end(), array<ll, 3>{k, LLONG_MAX, LLONG_MAX}) - ls_pts.begin() - 1;
    return i < 0 ? -1 : ls_pts[ls_best[i]][2];
}
