// lowercase strings, node 0 is the root
struct string_trie {
    vector<array<int, 26>> nxt;
    vector<int> pref, cnt;   // pref = words passing through node, cnt = words ending at node

    string_trie() { new_node(); }

    int new_node() {
        nxt.push_back({});
        pref.push_back(0);
        cnt.push_back(0);
        return nxt.size() - 1;
    }

    void insert(string s) {
        int v = 0;
        pref[0]++;
        for (char c : s) {
            int i = c - 'a';
            if (!nxt[v][i]) {
                int u = new_node();
                nxt[v][i] = u;
            }
            v = nxt[v][i];
            pref[v]++;
        }
        cnt[v]++;
    }

    int find(string s) {     // node of s, or -1
        int v = 0;
        for (char c : s) {
            v = nxt[v][c - 'a'];
            if (!v) return -1;
        }
        return v;
    }

    int count(string s) {
        int v = find(s);
        return v == -1 ? 0 : cnt[v];
    }

    int count_prefix(string s) {
        int v = find(s);
        return v == -1 ? 0 : pref[v];
    }
};
