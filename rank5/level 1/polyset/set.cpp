#include "set.hpp"

set::set(searchable_bag &srcBag) : bagRef(srcBag) {}
 
set::~set() {}
 
bool	set::has(int value) const
{
	return (this->bagRef.has(value));
}
 
void	set::insert(int value)
{
	if (this->bagRef.has(value) == false)
		this->bagRef.insert(value);
}
 
void	set::insert(int *array, int count)
{
	int	i = 0;
 
	while (i < count)
	{
		this->insert(array[i]);
		i++;
	}
}
 
void	set::print() const
{
	this->bagRef.print();
}
 
void	set::clear()
{
	this->bagRef.clear();
}
 
const searchable_bag	&set::get_bag() const
{
	return (this->bagRef);
}