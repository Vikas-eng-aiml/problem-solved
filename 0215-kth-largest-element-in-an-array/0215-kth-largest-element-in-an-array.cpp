class Solution {
public:
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] > pivot) {  
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left <= right) {
        int pi = partition(nums, left, right);

        if (pi == k - 1)
            return nums[pi];
        else if (pi > k - 1)
            return quickSelect(nums, left, pi - 1, k);
        else
            return quickSelect(nums, pi + 1, right, k);
    }
    return -1;  
}
    int findKthLargest(vector<int>& nums, int k) {
           return quickSelect(nums, 0, nums.size() - 1, k);
    }
};