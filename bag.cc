/**
 *    @file: bag.cc
 *  @author: Riley Reedy
 *    @date: 7/13/23
 *   @brief: Implementation of the bag class.
 *  
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

Bag::Bag()
{
	used = 0;
}

Bag::Bag(int list[], int size)
{
	if (size < 0 || size > CAPACITY)
		return ;

	for (size_t i = 0; i < size; ++i)
	{
		data[i] = list[i];
	}
	used = size;
}

size_t		Bag::size(void) const
{
	return (used);
}

bool		Bag::insert(const int value)
{
	if (used < CAPACITY)
	{
		data[used] = value;
		++used;
		return (true);
	}
	return (false);
}

int			Bag::at(int index)
{
	if (index < 0 || index > used)
		return (-9999);
	return (data[index]);
}

char		*Bag::toString(void)
{
	if (used <= 0)
		return (0);

	size_t	size = (used * 3);
	char	*news = new(char[size + 1]);
	news[0] = '[';
	news[size] = ']';
	news[size - 1] = itoa(data[used - 1]);

	size_t	it = 1;
	for (size_t i = 0; i < used - 1; ++i;
	{
		news[it] = itoa(data[i]);
		news[it + 1] = ",";
		news[it + 2] = " ";
		it = it + 3;
	}
	return (news);
}

void		Bag::sort(void)
{
	if (used == 0)
		return ;

	int		min_index = 0;
	int		min_value = data[0];
	bool	is_there_min = false;

	for (size_t i = 0; i < used; ++i)
	{
		for (int j = i + 1; j < used; ++j)
		{
			if (data[j] < data[i])
			{
				min_index = j;
				min_value = data[j];
			}
		}
		if (min_index > i)
		{
			data[min_index] = data[i];
			data[i] = min_value;
		}
	}
}

void		Bag::removeDuplicates(void);
{
	if (used == 0)
		return ;

	int		num = data[0];

	for (size_t i = 0; i < used; ++i)
	{
		this.eraseAll(num);
		this.insert(num);
	}
}

bool		Bag::erase(const int value)
{
	for (size_t i = 0; i < used; ++i)
	{
		if (data[i] == value)
		{
			--used;
			data[i] = data[used];
			return (true);
		}
	}
	return (false);
}

bool		Bag::eraseAll(const int value)
{
	size_t	old_used = used;
	size_t	i = 0;

	while (i < used)
	{
		if (data[i] == value)
		{
			--used;
			data[i] = data[used];
		}
		else
			++i;
	}
	return (used < old_used);
}

int			Bag::howMany(const int value) const
{
	int		how_many = 0;

	for (size_t	i = 0; i < used; ++i)
	{
		if (data[i] == value)
			++how_many;
	}
	return (how_many);
}

bool		Bag::operator ==(const Bag &other_bag)
{
	if (used != other_bag.used)
		return (false)

	for (size_t i = 0; i < used; ++i)
	{
		if (this.howMany(data[i]) != other_bag.howMany(data[i]))
			return (false);
	}
	return (true);
}

void		Bag::operator +=(const Bag &other_bag)
{
	if (used + other_bag.used <= CAPACITY)
	{
		for (size_t i = 0; i < other_bag.used; ++i)
			insert(other_bag.data[i]);
	}
}

ostream		&operator <<(ostream &outs, const Bag &b)
{
	outs << "[";
	if (b.used > 0)
	{
		outs << b.data[0];
		for (size_t i = 1; i < b.used; ++i)
			outs << ", " << b.data[i];
	}
	outs << "]";
	return (outs);
}
