#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
  return x * cos(x*x + y);
}

double Simpson(double a, double b, double c, double d, int n, int m) {
  double h = (b-a)/n;
  double k = (d-c)/m;
  double result = 0.0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      double x = a + i * h;
      double y = c + j * k;
      double factor = 1.0;
      if (i == 0 || i == n) factor *= 1.0;
      else if (i % 2 == 1) factor *= 4.0;
      else factor *= 2.0;
      if (j == 0 || j == m) factor *= 1.0;
      else if (j % 2 == 1) factor *= 4.0;
      else factor *= 2.0;
      result += factor * f(x, y);
    }
  }
  double hk = h * k;
  return hk * result / 9.0;
}

int main() {
  double a = 40, b = 60, c = 80, d = 120;
  int n = 3000, m = 3000;
  double estimate = Simpson(a, b, c, d, n, m);
  cout << "Estimate: " << estimate << endl;
  return 0;
}
