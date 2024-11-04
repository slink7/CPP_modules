#include "Point.hpp"

Point::Point() {
	x = Fixed(0);
	y = Fixed(0);
}

Point::Point(const float x, const float y) {
	this->x = Fixed(x);
	this->y = Fixed(y);
}

Point::Point(const Fixed x, const Fixed y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point& other) {
	*this = other;
}

Point::~Point() {

}


Point&	Point::operator=(const Point& other) {
	x = other.x;
	y = other.y;
	return (*this);
}

Point	Point::operator-(const Point& other) const {
	return (Point(x - other.getX(), y - other.getY()));
}

std::ostream &operator<<(std::ostream &stream, const Point& point)
{
	stream << "(" << point.getX() << ", " << point.getY() << ")";
	return (stream);
}

void	Point::setX(const Fixed& x) {
	this->x = x;
}

Fixed	Point::getX() const {
	return (x);
}

void	Point::setY(const Fixed& y) {
	this->y = y;
}

Fixed	Point::getY() const {
	return (y);
}

Fixed Point::perpdot(Point &other)
{
	return Fixed(y * other.getX() - x * other.getY());
}
