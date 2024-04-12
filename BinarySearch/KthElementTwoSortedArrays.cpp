#include <vector>

using namespace std;

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
  int r1 = 0, r2 = 0;
  int served = 0;

  while (served < k) {
    if (r1 < m && r2 < n) {
      if (row1[r1] <= row2[r2]) {
        served++;
        if (served == k)
          return row1[r1];
        r1++;
      } else {
        served++;
        if (served == k)
          return row2[r2];
        r2++;
      }
    } else if (r1 < m) {
      served++;
      if (served == k)
        return row1[r1];
      r1++;
    } else if (r2 < n) {
      served++;
      if (served == k)
        return row2[r2];
      r2++;
    }
  }

  return -1; 
}