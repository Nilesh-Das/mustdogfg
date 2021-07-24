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

// convert binary tree to doubly linked list

void print(TreeNode *head) {
  while(head) {
    cout << head->val << ' ';
    head = head->right;
  }
  cout << '\n';
}

void convert_to_dll(TreeNode* root, TreeNode **head) {
  if(root == NULL) return;
  static TreeNode* prev = NULL;
  convert_to_dll(root->left, head);
 
  if(prev == NULL) {
    *head = root;
  } else {
    root->left = prev;
    prev->right = root;
  }
  prev = root;

  convert_to_dll(root->right, head);
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<string> arr = {"20","8","22","4","12","#","#","#","#","10","14"};
  int n = arr.size();
  TreeNode* root = build_tree(arr, n);
  
  TreeNode* head = NULL;
  convert_to_dll(root, &head);
  print(head);

  return 0;
}