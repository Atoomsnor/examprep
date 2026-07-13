#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &rhs) : bag(rhs), array_bag(rhs), searchable_bag(rhs)
{
}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &rhs)
{
	array_bag::operator=(rhs);
	return (*this);
}

searchable_array_bag::~searchable_array_bag() {}

bool	searchable_array_bag::has(int value) const
{
	int	i = 0;

	while (i < this->size)
	{
		if (this->data[i] == value)
			return (true);
		i++;
	}
	return (false);
}