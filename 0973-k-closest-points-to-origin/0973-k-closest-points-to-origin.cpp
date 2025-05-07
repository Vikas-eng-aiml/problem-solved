class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < points.size(); ++i) {
        int x = points[i][0], y = points[i][1];
        int dist = x * x + y * y;
        maxHeap.emplace(dist, i);
        if (maxHeap.size() > k) {
            maxHeap.pop(); 
        }
    }

    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(points[maxHeap.top().second]);
        maxHeap.pop();
    }

    return result; 
    }
};