// directed, nodes 1..n; returns a cycle as [a, ..., a] in edge order, or empty if the graph is a DAG
vector<vector<int>> adj;
vector<int> par, state;   // state: 0 = unvisited, 1 = on stack, 2 = done
int cyc_start, cyc_end;

bool dfs(int u) {
    state[u] = 1;
    for (int v : adj[u]) {
        if (state[v] == 0) {
            par[v] = u;
            if (dfs(v)) return true;
        } else if (state[v] == 1) {
            cyc_start = v;
            cyc_end = u;
            return true;
        }
    }
    state[u] = 2;
    return false;
}

vector<int> find_cycle(int n) {
    par.assign(n + 1, -1);
    state.assign(n + 1, 0);
    for (int s = 1; s <= n; s++) {
        if (state[s] == 0 && dfs(s)) {
            vector<int> cyc = {cyc_start};
            for (int v = cyc_end; v != cyc_start; v = par[v]) cyc.push_back(v);
            cyc.push_back(cyc_start);
            reverse(cyc.begin(), cyc.end());
            return cyc;
        }
    }
    return {};
}
