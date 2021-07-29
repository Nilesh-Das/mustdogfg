#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
};

int len(Node *head) {
    int count = 0;
    while(head) {
        count++;
        head = head->next;
    }
    return count;
}

void print(Node* head) {
    while(head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}

Node* rotate(Node* head, int k) {
    if(head == NULL) return NULL;
    Node *fast = head, *slow = head;
    int n = len(head);
    for(int i = 0; i < k%n; i++) 
        fast = fast->next;
    if(fast == NULL) return head;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    if(slow->next == NULL) return head; 
    Node *temp = slow->next;
    slow->next = NULL;
    fast->next = head;
    
    return temp;
}

void solve(vector<int> a, int k) {
    int n = a.size();
    Node* head = new Node();
    Node* curr = head;
    for(int i = 0; i < n; i++) {
        curr->val = a[i];
        if(i < n-1) curr->next = new Node();
        curr = curr->next;
    }
    print(head);
    head = rotate(head, k);
    print(head);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        solve(a, k);
    }

    return 0;
}