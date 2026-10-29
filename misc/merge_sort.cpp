// 0-indexed, sorts a[l..r] in place, returns the number of inversions (pairs i < j with a[i] > a[j])
// to customize: change the element type and the comparison in the merge step (a[i] <= a[j])
vector<ll> tmp;

ll merge_sort(vector<ll>& a, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    ll inv = merge_sort(a, l, m) + merge_sort(a, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else { tmp[k++] = a[j++]; inv += m - i + 1; }
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (k = l; k <= r; k++) a[k] = tmp[k];
    return inv;
}

ll merge_sort(vector<ll>& a) {
    tmp.assign(a.size(), 0);
    return merge_sort(a, 0, (int)a.size() - 1);
}