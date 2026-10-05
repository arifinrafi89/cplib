// descending / min-heap without a comparator:
//   set<ll, greater<ll>> s;
//   priority_queue<ll, vector<ll>, greater<ll>> pq;   // min-heap

// custom order: first ascending, then second descending
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

// set<pair<int, int>, cmp> s;
// priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;   // top = LAST element in cmp order
