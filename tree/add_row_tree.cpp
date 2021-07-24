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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode *node;
        if(d == 1) {
            node = new TreeNode(v);
            node->left = root;
            return node;
        }
        
        queue<TreeNode*> q;
        q.push({root, 1});
        TreeNode* temp; int x=1;
        
        for(int x = 1; x < d-1; x++) {
            while(!q.empty()) {
                node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        while(!q.empty()) {
            node = q.front();
            q.pop();
            
            temp = node->left;
            node->left = new TreeNode(v);
            node->left->left = temp;

            temp = node->right;
            node->right = new TreeNode(v);
            node->right->right = temp;
        }

        return root;
    }
};