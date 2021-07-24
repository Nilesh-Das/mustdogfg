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

// maximum path sum
int dfs(TreeNode *root, int &best) {
  if(root == NULL) return 0;
  int l = max(0, dfs(root->left, best));
  int r = max(0, dfs(root->right, best));
  int curr = l + r + root->val;
  best = max(best, curr);
  return root->val + max(l ,r);
} 

int maxPathSum(TreeNode* root) {
  int best = INT_MIN;
  dfs(root, best);
  return best;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<string> arr = {"20","8","22","4","12","#","#","#","#","10","14"};
  int n = arr.size();
  TreeNode* root = build_tree(arr, n);
  
  cout << maxPathSum(root) << '\n';

  return 0;
}