#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

template <typename T>
TreeNode* build_tree(vector<T>& nodes, int n, T null="#") {
    TreeNode *root = new TreeNode(stoi(nodes[0])); 
    queue<TreeNode*> q;
    q.push(root);
    bool is_left = true;
    TreeNode *cur = NULL;

    for (int i = 1; i < n; i++) {
        TreeNode *node = NULL;
        if (nodes[i] != null) {
            node = new TreeNode(stoi(nodes[i]));
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

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string res;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *curr;

    while(!q.empty()) {
        curr = q.front();
        q.pop();

        if(curr != NULL) {
            res += to_string(curr->val) + ",";

            q.push(curr->left);
            q.push(curr->right);
        } else {
            res += "#,";
        }
    }
    res.pop_back(); // last comma
    return res;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    vector<string> nodes;

    stringstream ss(data);
    while(ss.good()) {
        string substr;
        getline(ss, substr, ',');
        nodes.push_back(substr);
    }
    int n = nodes.size();

    if(n == 1) {
        if(nodes[0] == "#") return NULL;
        TreeNode *root = new TreeNode(stoi(nodes[0])); 
        return root;
    }

    TreeNode *root = new TreeNode(stoi(nodes[0])); 
    queue<TreeNode*> q;
    q.push(root);
    bool is_left = true;
    TreeNode *cur = NULL;

    for (int i = 1; i < n; i++) {
        TreeNode *node = NULL;
        if (nodes[i] != "#") {
            node = new TreeNode(stoi(nodes[i]));
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

void levelOrder(TreeNode *root) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();

        cout << curr->val << ' ';

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> arr = {"1","2","3","#","#","4","5"};
    int n = arr.size();
    TreeNode* root = deserialize(serialize(build_tree(arr, n)));
    levelOrder(root);

    return 0;
}
