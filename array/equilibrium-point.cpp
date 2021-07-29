#include <bits/stdc++.h>
using namespace std;

int equilibrium(vector<int> arr)
{
	int n = arr.size();

	int right = 0;
	int left = 0;

	for (int i = 0; i < n; ++i)
		right += arr[i];

	for (int i = 0; i < n; ++i)
	{
		right -= arr[i];
		if (left == right) return i;
		left += arr[i];
	}

	return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
	}
	return 0;
}
