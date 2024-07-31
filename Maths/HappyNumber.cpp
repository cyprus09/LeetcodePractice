/* notice a pattern for different numbers post n >= 3 digits
it would never cross the threshold and if it's a two digit or one,
it will go to n >= 3 and after a point it is bound to again cross
the same number twice which we can use to detect cycles */
#include <cmath>

using namespace std;

class Solution
{
private:
  int getNext(int n)
  {
    int sum = 0;
    while (n > 0)
    {
      int digit = n % 10;
      n /= 10;
      sum += pow(digit, 2);
    }
    return sum;
  }

public:
  bool isHappy(int n)
  {
    int slow = n;
    int fast = getNext(n);

    while (slow != fast && fast != 1)
    {
      slow = getNext(slow);
      fast = getNext(getNext(fast));
    }

    return fast == 1 ? true : false;
  }
};