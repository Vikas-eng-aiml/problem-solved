class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    int n = servers.size(), m = tasks.size();
    vector<int> ans(m);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> free;
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> busy;

    for (int i = 0; i < n; ++i) {
        free.emplace(servers[i], i);
    }

    long long time = 0;

    for (int i = 0; i < m; ++i) {
        time = max(time, (long long)i);
        while (!busy.empty() && get<0>(busy.top()) <= time) {
            auto [end_time, weight, idx] = busy.top();
            busy.pop();
            free.emplace(weight, idx);
        }

        if (free.empty()) {
            time = get<0>(busy.top());
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [end_time, weight, idx] = busy.top();
                busy.pop();
                free.emplace(weight, idx);
            }
        }

        auto [weight, idx] = free.top();
        free.pop();
        ans[i] = idx;
        busy.emplace(time + tasks[i], weight, idx);
    }

    return ans;
    
    }
};