// 0 indexed, no lazy
#define ll long long

class SegmentTree {
private:
	ll n;
	vector<ll> tree;

	void build(ll node, ll start, ll end, vector<ll> &v) {
		if (start == end) {
			tree[node] = v[start];
		}
		else {
			ll mid = start + (end - start) / 2;
			build(2 * node + 1, start, mid, v);
			build(2 * node + 2, mid + 1, end, v);
			tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
		}
		return;
	}
	void update(ll node, ll start, ll end, ll idx, ll val) {
		if (start == end) {
			tree[node] += val;
		}
		else {
			ll mid = start + (end - start) / 2;
			if (start <= idx && idx <= mid) {
				update(2 * node + 1, start, mid, idx, val);
			}
			else {
				update(2 * node + 2, mid + 1, end, idx, val);
			}
			tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
		}
		return;
	}

	ll query(ll node, ll start, ll end, ll l, ll r) {
		if (r < start || l > end) {
			return 0;
		}
		else if (l <= start && end <= r) {
			return tree[node];
		}
		else {
			ll mid = start + (end - start) / 2;
			ll sum = 0;
			sum += query(2 * node + 1, start, mid, l, r);
			sum += query(2 * node + 2, mid + 1, end, l, r);
			return sum;
		}
		return 0;
	}

public:
	SegmentTree(vector<ll> &v) {
		n = v.size();
		tree.resize(4 * n);
		build (0, 0, n - 1, v);
	}

	void update(ll idx, ll val) {
		update(0, 0, n - 1, idx, val);
	}

	ll query(ll l, ll r) {
		return query(0, 0, n - 1, l, r);
	}
};
