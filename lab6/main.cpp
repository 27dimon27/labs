#include "poly/poly.h"
#include <iostream>

int main()
{
  Polynomial a;
  Polynomial b;
  std::cout << "Input poly1: ";
  std::cin >> a;
  std::cout << "Poly1: " << a << std::endl;
  std::cout << "Input poly2: ";
  std::cin >> b;
  Polynomial c = a;
  Polynomial d = b;
  Polynomial e = a;
  Polynomial f = b;
  std::cout << "Poly2: " << b << std::endl;
  std::cout << "Diff: Poly1 += Poly2" << std::endl;
  a += b;
  std::cout << "Poly1: " << a << std::endl;
  std::cout << "Poly2: " << b << std::endl;
  std::cout << std::endl;

  std::cout << "Poly1: " << c << std::endl;
  std::cout << "Poly2: " << d << std::endl;
  std::cout << "Poly1 + Poly2 = " << c + d << std::endl;
  std::cout << "Poly1: " << c << std::endl;
  std::cout << "Poly2: " << d << std::endl;
  std::cout << std::endl;

  std::cout << "Poly1: " << c << std::endl;
  std::cout << "Poly2: " << d << std::endl;
  std::cout << "Diff: Poly1 *= Poly2" << std::endl;
  c *= d;
  std::cout << "Poly1: " << c << std::endl;
  std::cout << "Poly2: " << d << std::endl;
  std::cout << std::endl;

  std::cout << "Poly1: " << e << std::endl;
  std::cout << "Poly2: " << f << std::endl;
  std::cout << "Poly1 * Poly2 = " << e * f << std::endl;
  std::cout << "Poly1: " << e << std::endl;
  std::cout << "Poly2: " << f << std::endl;

  return 0;
}