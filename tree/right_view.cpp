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

void print(vector<int> v) {
    for(int x : v) cout << x << ' ';
    cout << '\n';
}

vector<int> rightview(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    vector<int> res;
    TreeNode* node = NULL;
    int h = 0;

    while(!q.empty()) {
        tie(node, h) = q.front();
        q.pop();

        res.resize(h+1);
        res[h] = node->val;

        if(node->left) q.push({node->left, h+1});
        if(node->right) q.push({node->right, h+1});
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<char> arr = {'1','2','3','4'};
    int n = arr.size();
    TreeNode* root = build_tree(arr, n);
    print(rightview(root));

    return 0;
}