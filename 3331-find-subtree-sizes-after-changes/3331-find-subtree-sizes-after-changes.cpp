
class Solution {
public:
    vector<vector<int>> adj, modified;
    vector<int> ans, last;

    void build(int u, string &s) {
        int c = s[u] - 'a';

        int old = last[c];

        if (u != 0) {
            int p = (old == -1) ? -1 : old;

            if (p == -1) {
                // Original parent is handled separately
            } else {
                modified[p].push_back(u);
            }
        }

        last[c] = u;

        for (int v : adj[u]) {
            build(v, s);
        }

        last[c] = old;
    }

    int dfs(int u) {
        int sz = 1;

        for (int v : modified[u]) {
            sz += dfs(v);
        }

        ans[u] = sz;
        return sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.assign(n, {});
        modified.assign(n, {});
        ans.assign(n, 0);
        last.assign(26, -1);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Construct modified tree
        function<void(int)> buildTree = [&](int u) {
            int c = s[u] - 'a';
            int old = last[c];

            int p = (u == 0 || old == -1) ? parent[u] : old;

            if (u != 0) {
                modified[p].push_back(u);
            }

            last[c] = u;

            for (int v : adj[u]) {
                buildTree(v);
            }

            last[c] = old;
        };

        buildTree(0);

        // Calculate subtree sizes
        function<int(int)> getSize = [&](int u) {
            int sz = 1;

            for (int v : modified[u]) {
                sz += getSize(v);
            }

            return ans[u] = sz;
        };

        getSize(0);

        return ans;
    }
};
