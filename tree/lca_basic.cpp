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

void inorder(TreeNode* root) {
  if(root == NULL) return;
  inorder(root->left);
  cout << root->val << ' ';
  inorder(root->right);
}

// lca of binary tree

// iterative
TreeNode* lca1(TreeNode* root, TreeNode* p, TreeNode* q) {
  unordered_map<TreeNode*, TreeNode*> parent;
  stack<TreeNode*> stk;
  parent[root] = NULL;
  stk.push(root);
  while (!parent.count(p) || !parent.count(q)) {
    TreeNode *node = stk.top(); stk.pop();
    if(node->left) { parent[node->left]=node; stk.push(node->left); }
    if(node->right) { parent[node->right]=node; stk.push(node->right); }
  }
  set<TreeNode*> ancestors;
  while (p != NULL) { ancestors.insert(p); p=parent[p]; }
  while (!ancestors.count(q)) q = parent[q];
  return q;
}

// recursive
TreeNode* lca2(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(root==NULL || root==p || root==q) return root;
  TreeNode *l = lca2(root->left, p, q);
  TreeNode *r = lca2(root->right, p, q);
  if(l == NULL) return r;
  else if(r == NULL) return l;
  return root;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<string> arr = {"20","8","22","4","12","#","#","#","#","10","14"};
  int n = arr.size();
  TreeNode* root = build_tree(arr, n);
  
  TreeNode *p = root->left->left;
  TreeNode *q = root->left->right->right;
  cout << lca1(root, q, p)->val << '\n';
  cout << lca2(root, q, p)->val << '\n';

  return 0;
}