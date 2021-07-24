#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* build_tree(vector<char>& nodes, int n) {
    TreeNode *root = new TreeNode(nodes[0]-'0'); 
    queue<TreeNode*> q;
    q.push(root);
    bool is_left = true;
    TreeNode *cur = NULL;

    for (int i = 1; i < n; i++) {
        TreeNode *node = NULL;
        if (nodes[i] != '#') {
            node = new TreeNode(nodes[i]-'0');
            q.push(node);
        }

        if (is_left) {
            cur = q.front();
            q.pop();
            cur->left = node;
            is_left = false;
        } else {
            cur->right = node;
            is_left = true;
        }
    }

    return root;
}

bool checkbst(TreeNode* root, int64_t min=-1e12, int64_t max=1e12) {
    if(root == NULL) return true;
    
    if(root->val <= min || root->val >= max) return false;

    bool l = checkbst(root->left, min, root->val);
    bool r = checkbst(root->right, root->val, max);

    return l && r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<char> arr = {'1','2','3','4'};
    int n = arr.size();
    TreeNode* root = build_tree(arr, n);
    cout << checkbst(root) << '\n';

    return 0;
}