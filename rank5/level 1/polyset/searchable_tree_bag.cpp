#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &rhs) : bag(rhs), tree_bag(rhs), searchable_bag(rhs) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &rhs)
{
	tree_bag::operator=(rhs);
	return (*this);
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int value) const
{
	node	*current = this->tree;

	while (current)
	{
		if (value < current->value)
			current = current->l;
		else if (value > current->value)
			current = current->r;
		else
			return (true);
	}
	return (false);
}