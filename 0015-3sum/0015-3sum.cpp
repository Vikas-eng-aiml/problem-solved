class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
    vector<vector<int>> result;
    int target = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; 

        int ans = target - arr[i];
        int start = i + 1, end = arr.size() - 1;

        while (start < end) {
            int sum = arr[start] + arr[end];
            if (sum == ans) {
                result.push_back({arr[i], arr[start], arr[end]});
                while (start < end && arr[start] == arr[start + 1]) start++;
                while (start < end && arr[end] == arr[end - 1]) end--;

                start++;
                end--;
            } else if (sum < ans) {
                start++; 
            } else {
                end--; 
            }
        }
    }
    return result;
}
};
