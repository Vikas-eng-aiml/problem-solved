/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

    map<int, vector<pair<int, int>>> colTable;
    queue<tuple<TreeNode*, int, int>> q;

    q.push({root, 0, 0});

    while (!q.empty()) {
        auto [node, row, col] = q.front(); q.pop();
        colTable[col].emplace_back(row, node->val);

        if (node->left)
            q.push({node->left, row + 1, col - 1});
        if (node->right)
            q.push({node->right, row + 1, col + 1});
    }


    vector<vector<int>> result;
    for (auto& [col, vec] : colTable) {
        sort(vec.begin(), vec.end());
        vector<int> colVals;
        for (auto& [row, val] : vec) {
            colVals.push_back(val);
        }
        result.push_back(colVals);
    }

    return result;
}
};