#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (!inorder.size())
            return nullptr;
        int n = inorder.size();
        stack<TreeNode *> roots;
        int ii = n - 1, pi = n - 1;
        TreeNode *root = new TreeNode(postorder[pi--]), *cur = root;
        roots.push(cur);
        while (ii >= 0)
        { //pi can be negative but ii have reach 0
            while (!roots.empty() && inorder[ii] != roots.top()->val)
            {
                // Process roots.top() right subtree
                cur->right = new TreeNode(postorder[pi--]);
                cur = cur->right;
                roots.push(cur);
            }
            cur = roots.top();
            roots.pop(); // Done with cur node right subtree
            if (pi >= 0 && (roots.empty() || inorder[ii - 1] != roots.top()->val))
            { //roots can be empty.
                // cur node has left subtree
                cur->left = new TreeNode(postorder[pi--]);
                cur = cur->left;
                roots.push(cur);
            }
            --ii;
        }
        return root;
    }

    // TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    // {
    //     if (!inorder.size())
    //         return nullptr;
    //     int n = inorder.size();
    //     TreeNode *root = new TreeNode(postorder[n - 1]);
    //     int ii = n - 1, pi = n - 1;
    //     dfs(inorder, postorder, nullptr, root, ii, pi);
    //     return root;
    // }

    // void dfs(vector<int> &inorder, vector<int> &postorder, TreeNode *pre_inorder_root, TreeNode *root, int &ii, int &pi)
    // {
    //     if (ii < 0)
    //         return;
    //     if (inorder[ii] != root->val)
    //     { //right subtree
    //         root->right = new TreeNode(postorder[--pi]);
    //         dfs(inorder, postorder, root, root->right, ii, pi); //notice the change of ii will be passed back
    //     }
    //     if (inorder[ii] == root->val)
    //     {         //left subtree
    //         --ii; //whenever found inorder[ii]==root->val, done with its right subtree, i minus 1
    //         if (pi > 0 && (pre_inorder_root == nullptr || (ii >= 0 && inorder[ii] != pre_inorder_root->val)))
    //         {
    //             root->left = new TreeNode(postorder[--pi]);
    //             dfs(inorder, postorder, pre_inorder_root, root->left, ii, pi); //keep the predecessor of root in inorder traversal.
    //         }
    //     }
    // }
};
