#pragma once

#include <ostream>

class vect2
{
	private:
		int	x;
		int y;

	public:
		vect2();
		vect2(int x, int y);
		vect2(int z);

		// vect2(const vect2 &rhs);
		// vect2	&operator=(const vect2 &rhs);
		// ~vect2();

		int		&operator[](unsigned int nbr);
		int		operator[](unsigned int nbr) const;

		vect2	operator++(int);
		vect2	&operator++();
		vect2	operator--(int);
		vect2	&operator--();

		vect2	&operator+=(const vect2 &rhs);
		vect2	&operator-=(const vect2 &rhs);
		vect2	&operator*=(const vect2 &rhs);

		vect2	operator+(const vect2 &rhs) const;
		vect2	operator-(const vect2 &rhs) const;
		vect2	operator*(const vect2 &rhs) const;

		vect2	operator-() const;

		bool	operator==(const vect2 &rhs) const;
		bool	operator!=(const vect2 &rhs) const;

};

std::ostream	&operator<<(std::ostream &lhs, const vect2 &rhs);