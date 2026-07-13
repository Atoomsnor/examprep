
#include "bigint.hpp"
#include <sstream>
#include <algorithm>
 
bigint::bigint() : digits("0") {}
 
bigint::bigint(unsigned long value)
{
	std::ostringstream	oss;
 
	oss << value;
	this->digits = oss.str();
}
 
bigint::bigint(std::string num) : digits(num)
{
	this->trimLeadingZeros();
}
 
bigint::bigint(const bigint &rhs)
{
	*this = rhs;
}
 
bigint::~bigint() {}
 
bigint	&bigint::operator=(const bigint &rhs)
{
	if (this != &rhs)
	{
		this->digits = rhs.digits;
	}
	return (*this);
}
 
void	bigint::trimLeadingZeros()
{
	while (this->digits.size() > 1 && this->digits[0] == '0')
		this->digits.erase(0, 1);
	if (this->digits.empty())
		this->digits = "0";
}
 
size_t	bigint::toShiftCount(const bigint &rhs) const
{
	size_t	count = 0;
	size_t	i = 0;
 
	while (i < rhs.digits.size())
	{
		count = count * 10 + (rhs.digits[i] - '0');
		i++;
	}
	return (count);
}
 
void	bigint::halve()
{
	std::string	result;
	int			carry = 0;
	size_t		i = 0;
 
	while (i < this->digits.size())
	{
		int current = carry * 10 + (this->digits[i] - '0');
		result += (current / 2) + '0';
		carry = current % 2;
		i++;
	}
	this->digits = result;
	this->trimLeadingZeros();
}
 
bigint	&bigint::operator+=(const bigint &rhs)
{
	std::string	result;
	size_t		i = this->digits.size();
	size_t		j = rhs.digits.size();
	int			hold = 0;
 
	while (i > 0 || j > 0 || hold)
	{
		int sum = hold;
		if (i > 0)
			sum += this->digits[--i] - '0';
		if (j > 0)
			sum += rhs.digits[--j] - '0';
		hold = sum / 10;
		result += (sum % 10) + '0';
	}
	std::reverse(result.begin(), result.end());
	this->digits = result;
	return (*this);
}
 
bigint	bigint::operator+(const bigint &rhs) const
{
	bigint outcome = *this;
 
	outcome += rhs;
	return (outcome);
}
 
bigint	&bigint::operator++()
{
	*this += 1;
	return (*this);
}
 
bigint	bigint::operator++(int)
{
	bigint temp = *this;
 
	*this += 1;
	return (temp);
}
 
bigint	&bigint::operator<<=(const bigint &rhs)
{
	size_t	count = this->toShiftCount(rhs);
	size_t	i = 0;
 
	while (i < count)
	{
		*this += *this;
		i++;
	}
	return (*this);
}
 
bigint	&bigint::operator>>=(const bigint &rhs)
{
	size_t	count = this->toShiftCount(rhs);
	size_t	i = 0;
 
	while (i < count)
	{
		this->halve();
		i++;
	}
	return (*this);
}
 
bigint	bigint::operator<<(const bigint &rhs) const
{
	bigint outcome = *this;
 
	outcome <<= rhs;
	return (outcome);
}
 
bigint	bigint::operator>>(const bigint &rhs) const
{
	bigint outcome = *this;
 
	outcome >>= rhs;
	return (outcome);
}
 
bool	bigint::operator==(const bigint &rhs) const
{
	if (this->digits == rhs.digits)
		return (true);
	return (false);
}
 
bool	bigint::operator!=(const bigint &rhs) const
{
	return (!(*this == rhs));
}
 
bool	bigint::operator<(const bigint &rhs) const
{
	if (this->digits.size() != rhs.digits.size())
		return (this->digits.size() < rhs.digits.size());
	return (this->digits < rhs.digits);
}
 
bool	bigint::operator>(const bigint &rhs) const
{
	return (rhs < *this);
}
 
bool	bigint::operator<=(const bigint &rhs) const
{
	return (!(rhs < *this));
}
 
bool	bigint::operator>=(const bigint &rhs) const
{
	return (!(*this < rhs));
}
 
const std::string	&bigint::getDigits() const
{
	return (this->digits);
}
 
std::ostream	&operator<<(std::ostream &lhs, const bigint &rhs)
{
	lhs << rhs.getDigits();
	return (lhs);
}