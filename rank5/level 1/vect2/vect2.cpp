#include "vect2.hpp"

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

vect2::vect2(const vect2 &rhs) : x(0), y(0)
{
	*this = rhs;
}

vect2	&vect2::operator=(const vect2 &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return (*this);
}

int vect2::operator[](unsigned int num) const
{
	if (num == 0)
		return (this->x);
	return (this->y);
}

int &vect2::operator[](unsigned int num)
{
	if (num == 0)
		return (this->x);
	return (this->y);
}

vect2	vect2::operator++(int)
{
	vect2 temp = *this;
	this->x += 1;
	this->y += 1;
	return (temp);
}
vect2	&vect2::operator++()
{
	this->x += 1;
	this->y += 1;
	return (*this);
}
vect2	vect2::operator--(int)
{
	vect2 temp = *this;
	this->x -= 1;
	this->y -= 1;
	return (temp);
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
	vect2 temp = *this;
	temp.x += rhs.x;
	temp.y += rhs.y;
	return (temp);
}

vect2	vect2::operator-(const vect2 &rhs) const
{
	vect2 temp = *this;
	temp.x -= rhs.x;
	temp.y -= rhs.y;
	return (temp);
}

vect2	vect2::operator*(const vect2 &rhs) const
{
	vect2 temp = *this;
	temp.x *= rhs.x;
	temp.y *= rhs.y;
	return (temp);
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

std::ostream &operator<<(std::ostream &lhs, const vect2 &rhs)
{
	std::cout << "{" << rhs[0] << ", " << rhs[1] << "}";
	return (lhs);
}