#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    // Runtime: 24 ms, faster than 37.12% of C++ online submissions for Trim a Binary Search Tree.
    // Memory Usage: 21.3 MB, less than 100.00% of C++ online submissions for Trim a Binary Search Tree.
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (!root)
            return nullptr;
        if (root->val < L)
            return trimBST(root->right, L, R);
        else if (root->val > R)
            return trimBST(root->left, L, R);

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};