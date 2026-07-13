#include "vect2.hpp"
#include <iostream>

vect2::vect2() : x(0), y(0) {}
vect2::vect2(int x, int y)
{
	this->x = x;
	this->y = y;
}

vect2::vect2(int z)
{
	this->x = z;
	this->y = z;
}

// vect2::vect2(const vect2 &rhs)
// {
// 	*this = rhs;
// }

// vect2	&vect2::operator=(const vect2 &rhs)
// {
// 	if (this != &rhs)
// 	{
// 		this->x = rhs.x;
// 		this->y = rhs.y;
// 	}
// 	return (*this);
// }

// vect2::~vect2() {}


int		&vect2::operator[](unsigned int nbr)
{
	if (nbr == 0)
		return (x);
	return (y);
}

int		vect2::operator[](unsigned int nbr) const
{
	if (nbr == 0)
		return (x);
	return (y);
}

vect2	vect2::operator++(int)
{
	vect2 tmp = *this;

	this->x += 1;
	this->y += 1;
	return (tmp);
}

vect2	&vect2::operator++()
{
	this->x += 1;
	this->y += 1;
	return (*this);
}

vect2	vect2::operator--(int)
{
	vect2 tmp = *this;

	this->x -= 1;
	this->y -= 1;
	return (tmp);
}

vect2	&vect2::operator--()
{
	this->x -= 1;
	this->y -= 1;
	return (*this);
}

vect2	&vect2::operator+=(const vect2 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	return (*this);
}

vect2	&vect2::operator-=(const vect2 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return (*this);
}

vect2	&vect2::operator*=(const vect2 &rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	return (*this);
}

vect2	vect2::operator+(const vect2 &rhs) const
{
	vect2 tmp = *this;

	tmp.x += rhs.x;
	tmp.y += rhs.y;
	return (tmp);
}

vect2	vect2::operator-(const vect2 &rhs) const
{
	vect2 tmp = *this;

	tmp.x -= rhs.x;
	tmp.y -= rhs.y;
	return (tmp);
}

vect2	vect2::operator*(const vect2 &rhs) const
{
	vect2 tmp = *this;

	tmp.x *= rhs.x;
	tmp.y *= rhs.y;
	return (tmp);
}

vect2	vect2::operator-() const
{
	vect2 temp = *this;

	temp.x = -x;
	temp.y = -y;
	return (temp);
}

bool	vect2::operator==(const vect2 &rhs) const
{
	if ((this->x == rhs.x) && (this->y == rhs.y))
		return (true);
	return (false);
}

bool	vect2::operator!=(const vect2 &rhs) const
{
	return (!(*this == rhs));
}

std::ostream	&operator<<(std::ostream &lhs, const vect2 &rhs)
{
	std::cout << "{" << rhs[0] << ", " << rhs[1] << "}";
	return (lhs);
}