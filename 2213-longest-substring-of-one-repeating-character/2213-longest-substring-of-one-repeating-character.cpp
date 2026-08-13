class Solution {
public:
    struct Node {
        char lc, rc;
        int ll, rr, best, len;

        Node() : lc(0), rc(0), ll(0), rr(0), best(0), len(0) {}
        Node(char c) : lc(c), rc(c), ll(1), rr(1), best(1), len(1) {}
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.ll = a.ll;
        if (a.ll == a.len && a.rc == b.lc)
            res.ll = a.len + b.ll;

        res.rr = b.rr;
        if (b.rr == b.len && a.rc == b.lc)
            res.rr = b.len + a.rr;

        res.best = max(a.best, b.best);

        if (a.rc == b.lc)
            res.best = max(res.best, a.rr + b.ll);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(node * 2, l, mid, pos, c);
        else
            update(node * 2 + 1, mid + 1, r, pos, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;

            update(1, 0, n - 1, pos, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};