class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
       int n = tasks.size();
    vector<int> result;

    vector<tuple<int, int, int>> taskList;
    for (int i = 0; i < n; ++i) {
        taskList.emplace_back(tasks[i][0], tasks[i][1], i);  
    }

    sort(taskList.begin(), taskList.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    long long time = 0;
    int i = 0;

    while (i < n || !pq.empty()) {
        while (i < n && get<0>(taskList[i]) <= time) {
            pq.emplace(get<1>(taskList[i]), get<2>(taskList[i]));
            ++i;
        }

        if (!pq.empty()) {
            auto [procTime, index] = pq.top();
            pq.pop();
            time += procTime;
            result.push_back(index);
        } else {
            time = get<0>(taskList[i]);
        }
    }

    return result; 
    }
};