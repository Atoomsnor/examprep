#include "bigint.hpp"
#include <sstream>

bigint::bigint() : digits("0")
{
}

bigint::bigint(unsigned long value)
{
	std::ostringstream	oss;

	oss << value;
	digits = oss.str();
	trimLeadingZeros();
}

bigint::bigint(const std::string &value) : digits(value)
{
	trimLeadingZeros();
}

bigint::bigint(const bigint &rhs) : digits(rhs.digits)
{
}

bigint::~bigint()
{
}

bigint	&bigint::operator=(const bigint &rhs)
{
	if (this != &rhs)
		digits = rhs.digits;
	return (*this);
}

void	bigint::trimLeadingZeros()
{
	size_t	firstNonZero = digits.find_first_not_of('0');

	if (firstNonZero == std::string::npos)
		digits = "0";
	else
		digits = digits.substr(firstNonZero);
}

unsigned long	bigint::toShiftCount() const
{
	std::istringstream	iss(digits);
	unsigned long		value;

	iss >> value;
	return (value);
}

bigint	&bigint::operator+=(const bigint &rhs)
{
	std::string	result;
	int			carry = 0;
	int			i = static_cast<int>(digits.size()) - 1;
	int			j = static_cast<int>(rhs.digits.size()) - 1;

	while (i >= 0 || j >= 0 || carry)
	{
		int	sum = carry;

		if (i >= 0)
			sum += digits[i--] - '0';
		if (j >= 0)
			sum += rhs.digits[j--] - '0';
		carry = sum / 10;
		result.insert(result.begin(), static_cast<char>('0' + (sum % 10)));
	}
	digits = result;
	trimLeadingZeros();
	return (*this);
}

bigint	bigint::operator+(const bigint &rhs) const
{
	bigint	outcome = *this;

	outcome += rhs;
	return (outcome);
}

bigint	&bigint::operator++()
{
	*this += bigint(static_cast<unsigned long>(1));
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	outcome = *this;

	*this += bigint(static_cast<unsigned long>(1));
	return (outcome);
}

bigint	&bigint::operator<<=(const bigint &rhs)
{
	unsigned long	shift = rhs.toShiftCount();

	if (digits != "0")
	{
		for (unsigned long k = 0; k < shift; k++)
			digits += '0';
	}
	return (*this);
}

bigint	&bigint::operator>>=(const bigint &rhs)
{
	unsigned long	shift = rhs.toShiftCount();

	if (shift >= digits.size())
		digits = "0";
	else
		digits = digits.substr(0, digits.size() - shift);
	trimLeadingZeros();
	return (*this);
}

bigint	bigint::operator<<(const bigint &rhs) const
{
	bigint	outcome = *this;

	outcome <<= rhs;
	return (outcome);
}

bigint	bigint::operator>>(const bigint &rhs) const
{
	bigint	outcome = *this;

	outcome >>= rhs;
	return (outcome);
}

bool	bigint::operator==(const bigint &rhs) const
{
	return (digits == rhs.digits);
}

bool	bigint::operator!=(const bigint &rhs) const
{
	return (digits != rhs.digits);
}

bool	bigint::operator<(const bigint &rhs) const
{
	if (digits.size() != rhs.digits.size())
		return (digits.size() < rhs.digits.size());
	return (digits < rhs.digits);
}

bool	bigint::operator<=(const bigint &rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool	bigint::operator>(const bigint &rhs) const
{
	return (!(*this <= rhs));
}

bool	bigint::operator>=(const bigint &rhs) const
{
	return (!(*this < rhs));
}

const std::string	&bigint::getDigits() const
{
	return (digits);
}

std::ostream	&operator<<(std::ostream &lhs, const bigint &rhs)
{
	lhs << rhs.getDigits();
	return (lhs);
}