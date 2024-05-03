//linear search (naive approach): O(M x log2(n))
long long func(int b, int exp){
  //this function uses O(log2N) better than running an normal for loop = O(n)
  long long ans = 1;
  long long base = b;
  while(exp > 0) {
    if(exp % 2){
      exp--;
      ans = ans * base;
    }else {
      exp /= 2;
      base = base * base;
    }
  }

  return ans;
}


int NthRoot(int n, int m) {
  for (int i = 1; i <= m; i++) {
    long long val = func(i, n);
    if (val == m)
      return i;
    if (val > m)
      break;
  }

  return -1;
}

//binary search (optimal approach)
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