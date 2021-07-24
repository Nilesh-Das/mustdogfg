#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> prices) {
    int i = 0;
    int h = prices[0];
    int l = prices[0];
    int n = prices.size();
    int profit = 0;

    while(i < n-1) {
        while(i < n-1 && prices[i] >= prices[i+1]) i++;
        l = prices[i];
        while(i < n-1 && prices[i] <= prices[i+1]) i++;
        h = prices[i];

        profit += h-l;
    }

    return profit;
}

int main() {
  vector<int> prices = {1,2,3,4,5};
  cout << maxProfit(prices) << '\n';

  return 0;
}
