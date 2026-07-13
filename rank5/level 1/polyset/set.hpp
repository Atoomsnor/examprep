#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &bagRef;

		set();
		set(const set &rhs);
		set &operator=(const set &rhs);

	public:
		set(searchable_bag &srcBag);
		~set();

		bool	has(int value) const;
		void	insert(int value);
		void	insert(int *array, int count);
		void	print() const;
		void	clear();
 
		const searchable_bag	&get_bag() const;
};