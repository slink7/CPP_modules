
#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Point ab = b - a;
	Point bc = c - b;
	Point ca = a - c;

	Point ap = point - a;
	Point bp = point - b;
	Point cp = point - c;

	int dotA = ab.perpdot(ap).sign();
	int dotB = bc.perpdot(bp).sign();
	int dotC = ca.perpdot(cp).sign();

	std::cout << "AB:" << ab << "\nBC:" << bc << "\nCA:" << ca << "\n";
	std::cout << "AP:" << ap << "\nBP:" << bp << "\nCP:" << cp << "\n";
	std::cout << "A:" << ab.perpdot(ap) << "\nB:" << bc.perpdot(bp) << "\nC:" << ca.perpdot(cp) << "\n";
	std::cout << "sA:" << ab.perpdot(ap).sign() << "\nsB:" << bc.perpdot(bp).sign() << "\nsC:" << ca.perpdot(cp).sign() << "\n";

	return (
		(dotA + dotB + dotC == 3) ||
		(dotA + dotB + dotC == -3)
	);
}