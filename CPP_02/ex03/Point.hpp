#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed x, const Fixed y);
	Point(const Point& other);
	~Point();

	Point&	operator=(const Point& other);
	Point	operator-(const Point& other) const;

	void	setX(const Fixed& x);
	Fixed	getX(void) const;
	void	setY(const Fixed& y);
	Fixed	getY(void) const;
	Fixed	perpdot(Point& other);
private:
	Fixed x, y;
};

std::ostream &operator<<(std::ostream &stream, const Point& point);

#endif