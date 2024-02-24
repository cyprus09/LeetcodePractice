class Solution {
public:
    double myPow(double x, int n) {
      if(n == 0){
          return 1.0;
      }

      double halfPower = myPow(x, n / 2);

      if(n % 2 == 0){
          return halfPower * halfPower;
      }else{
          return (n > 0) ? x * halfPower * halfPower : (1/x) * halfPower * halfPower;
      }
    }
};