/*
  Construct Binary Tree from Inorder and Postorder Traversal

  Given inorder and postorder traversal of a tree, construct the binary tree.

  Note:
  You may assume that duplicates do not exist in the tree.
*/

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
    TreeNode *buildTreeHelper(vector<int> &inorder, int inLeft, int inRight,
                              vector<int> &postorder, int postLeft, int postRight) {
        if (inLeft > inRight) return NULL;
        // The last element in post-order sequence is the root of the tree.
        TreeNode *root = new TreeNode(postorder[postRight]);
        for (int i=inLeft; i<=inRight; i++) {
            // Find the root in the in-order sequence.
            if (inorder[i] == root->val) {
                int leftNum = i - inLeft;
                // The in-order sequence is split into two parts by the root.
                // The former part is left-sub-tree.
                root->left = buildTreeHelper(inorder, inLeft, i-1,
                                             postorder, postLeft, postLeft+leftNum-1);
                // The later part is right-sub-tree;
                root->right = buildTreeHelper(inorder, i+1, inRight,
                                              postorder, postLeft+leftNum, postRight-1);
                return root;
            }
        }
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        return buildTreeHelper(inorder, 0, n-1, postorder, 0, n-1);
    }
};
