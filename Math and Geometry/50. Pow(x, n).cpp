class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        long exp = static_cast<long>(n);
        return exp < 0 ? aux(1 / x, -exp) : aux(x, exp);
    }

   private:
    double aux(double x, long n) {
        if (n == 0) {
            return 1;
        }
        double half = aux(x, n / 2);
        return (n % 2 == 0) ? half * half : half * half * x;
    }
};