#pragma once

#include <iostream>
#include <string>

class bigint
{
	private:
		std::string	digits;

		void			trimLeadingZeros();
		unsigned long	toShiftCount() const;

	public:
		bigint();
		bigint(unsigned long value);
		bigint(const std::string &value);
		bigint(const bigint &rhs);
		~bigint();

		bigint	&operator=(const bigint &rhs);

		bigint	&operator+=(const bigint &rhs);
		bigint	operator+(const bigint &rhs) const;

		bigint	&operator++();
		bigint	operator++(int);

		bigint	&operator<<=(const bigint &rhs);
		bigint	&operator>>=(const bigint &rhs);
		bigint	operator<<(const bigint &rhs) const;
		bigint	operator>>(const bigint &rhs) const;

		bool	operator==(const bigint &rhs) const;
		bool	operator!=(const bigint &rhs) const;
		bool	operator<(const bigint &rhs) const;
		bool	operator<=(const bigint &rhs) const;
		bool	operator>(const bigint &rhs) const;
		bool	operator>=(const bigint &rhs) const;

		const std::string	&getDigits() const;
};

std::ostream	&operator<<(std::ostream &lhs, const bigint &rhs);