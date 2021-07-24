#include <bits/stdc++.h>
#define ll long long
using namespace std;

int nextGap(int gap)
{
  if (gap <= 1)
    return 0;
  return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m) 
{ 
  // insertion sort techinque
  // for(int i=n-1; i>=0; i--) {
  //     int j, last = arr1[m-1];
  //     for(j=m-2; j>=0 && arr1[j] > arr2[i]; j--) {
  //         arr1[j+1] = arr1[j];
  //     }
  //     if(j != m-2 || last > arr2[i]) {
  //         arr1[j+1] = arr2[i];
  //         arr2[i] = last;
  //     }
  // }

  int i, j, gap = n + m;
  for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
  {
        // comparing elements in the first array.
    for (i = 0; i + gap < n; i++)
      if (arr1[i] > arr1[i + gap])
        swap(arr1[i], arr1[i + gap]);

      // comparing elements in both arrays.
    for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
      if (arr1[i] > arr2[j])
        swap(arr1[i], arr2[j]);

    if (j < m) {
        // comparing elements in the second array.
      for (j = 0; j + gap < m; j++)
        if (arr2[j] > arr2[j + gap])
          swap(arr2[j], arr2[j + gap]);
    }
  }
} 

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  // given
  int arr1[] = {1,5,8};
  int arr2[] = {2,3,7};
  int n=3, m=3;

  
  merge(arr1, arr2, n, m);

  for(int i=0; i<n; i++) cout << arr1[i] << ' ';
  for(int j=0; j<m; j++) cout << arr2[j] << ' ';
  cout << '\n';

  return 0;
}