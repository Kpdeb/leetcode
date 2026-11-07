
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> available;

        priority_queue<pair<long long,pair<int,int>>,
            vector<pair<long long,pair<int,int>>>,
            greater<pair<long long,pair<int,int>>>> busy;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans;
        long long currentTime = 0;

        for(int i = 0; i < tasks.size(); i++) {

            currentTime = max(currentTime, (long long)i);

            // Release all servers that have become free
            while(!busy.empty() &&
                  busy.top().first <= currentTime) {

                auto p = busy.top();
                busy.pop();

                available.push(p.second);
            }

            // Wait if all servers are busy
            if(available.empty()) {

                currentTime = busy.top().first;

                while(!busy.empty() &&
                      busy.top().first <= currentTime) {

                    auto p = busy.top();
                    busy.pop();

                    available.push(p.second);
                }
            }

            // Select server with minimum weight and index
            auto server = available.top();
            available.pop();

            ans.push_back(server.second);

            // Schedule task completion
            busy.push({
                currentTime + tasks[i],
                server
            });
        }

        return ans;
    }
};
