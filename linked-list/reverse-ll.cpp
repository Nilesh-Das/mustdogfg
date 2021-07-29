#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
};

void print(Node* head) {
    while(head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}

void reverse(Node** head) {
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void solve(vector<int> a) {
    int n = a.size();
    Node* head = new Node();
    Node* curr = head;
    for(int i = 0; i < n; i++) {
        curr->val = a[i];
        if(i < n-1) curr->next = new Node();
        curr = curr->next;
    }
    print(head);
    reverse(&head);
    print(head);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        solve(a);
    }

    return 0;
}