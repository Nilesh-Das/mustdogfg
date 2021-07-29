#include <iostream>
using namespace std;

void rearrange(long long *arr, int n) 
{ 
	long long *res = (long long*)malloc(n * sizeof(long long));
	int j = 0;
	for(int i = 1; i < n; i += 2) {
		res[i] = arr[j++];
	}
	j = n - 1;
	for(int i = 0; i < n; i += 2) {
		res[i] = arr[j--];
	}
	for(int i = 0; i < n; i++) {
		arr[i] = res[i];
	}
}

int main() {
	return 0;
}
