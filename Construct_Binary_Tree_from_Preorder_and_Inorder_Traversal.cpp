/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTreeHelper(vector<int> &preorder, int preLeft, int preRight,
                              vector<int> &inorder, int inLeft, int inRight) {
        if (preLeft > preRight) return NULL;
        // The first element in pre-order sequence is the root of the tree.
        TreeNode *root = new TreeNode(preorder[preLeft]);
        for (int i=inLeft; i<=inRight; i++) {
            // Find the root in the in-order sequence.
            if (inorder[i] == root->val) {
                int leftNum = i - inLeft;
                // The in-order sequence is split into two parts by the root.
                // The former part is left-sub-tree.
                root->left = buildTreeHelper(preorder, preLeft+1, preLeft+leftNum,
                                             inorder, inLeft, i-1);
                // The later part is right-sub-tree;
                root->right = buildTreeHelper(preorder, preLeft+leftNum+1, preRight,
                                              inorder, i+1, inRight);
                return root;
            }
        }
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        return buildTreeHelper(preorder, 0, n-1, inorder, 0, n-1);
    }
};
