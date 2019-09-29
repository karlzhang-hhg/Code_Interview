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
};
