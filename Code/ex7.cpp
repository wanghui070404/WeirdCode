#include<bits/stdc++.h>

double fx(double x, double y)
{
  return x * cos(x * x + y);
}

double Simpson(double a, double b, double c, double d, int n, int m)
{
  double h = (b - a) / n;
  double k = (d - c) / m;
  double result = 0.0;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      double x = a + i * h;
      double y = c + j * k;
      double factor = 1.0;
      if (i == 0 || i == n)
        factor = factor * 1.0;
      else if (i % 2 == 1)
        factor = factor * 4.0;
      else
        factor = factor * 2.0;
      if (j == 0 || j == m)
        factor = factor * 1.0;
      else if (j % 2 == 1)
        factor = factor * 4.0;
      else
        factor = factor * 2.0;
      result += factor * fx(x, y);
    }
  }
  double hk = h * k;
  return hk * result / 9.0;
}

int main()
{
  double a, b, c, d;
  int m, n;
  std::cout << "Nhap gia tri a, b, c, d, m, n: ";
  std::cin >> a >> b >> c >> d >> m >> n;
  double estimate = Simpson(a, b, c, d, n, m);
  std::cout << "Estimate: " << estimate << std::endl;
  return 0;
}

