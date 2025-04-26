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
    int idx = 0;

    TreeNode* buildBST(vector<int>& preorder, int minVal, int maxVal) {
        if (idx >= preorder.size() || preorder[idx] < minVal || preorder[idx] > maxVal) {
            return NULL;
        }

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        root->left = buildBST(preorder, minVal, val - 1);
        root->right = buildBST(preorder, val + 1, maxVal);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, INT_MIN, INT_MAX);
    }
};
