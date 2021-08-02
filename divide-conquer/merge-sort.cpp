#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k;

    vector<int> L(n1), R(n2);
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i];
    for(int i = 0; i < n2; i++)
        R[i] = arr[m + i + 1];
    i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = L[j++];
}


void mergeSort(vector<int>& a, int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
}