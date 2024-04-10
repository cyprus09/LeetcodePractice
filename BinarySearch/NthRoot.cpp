int func(int n, int m, int mid) {
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= mid;
    if (ans > m)
      return 2;
  }
  if (ans == m)
    return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int low = 1;
  int high = m;
  while (low <= high) {
    int mid = (low + high) / 2;
    int midFunc = func(n, m, mid);
    if (midFunc == 1)
      return mid;
    else if (midFunc == 0)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}