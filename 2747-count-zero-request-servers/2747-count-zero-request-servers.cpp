
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        // Sort logs by timestamp
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store query and original index
        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(queries.size());
        unordered_map<int,int> mp;

        int l = 0, r = 0;

        for(auto [t, idx] : q) {

            // Add requests within the right boundary
            while(r < logs.size() && logs[r][1] <= t) {
                mp[logs[r][0]]++;
                r++;
            }

            // Remove requests outside the left boundary
            while(l < r && logs[l][1] < t - x) {
                mp[logs[l][0]]--;

                if(mp[logs[l][0]] == 0) {
                    mp.erase(logs[l][0]);
                }

                l++;
            }

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};
