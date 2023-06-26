#pragma once

template<typename list_item_type>
struct list
{
	list_item_type* local_list_address{};
	size_t local_item_size{};
	size_t local_total_size{};

	list(size_t item_num)
	{
		local_item_size = sizeof(list_item_type);
		local_total_size = item_num * sizeof(list_item_type);
		if (!local_item_size || !local_total_size)
			return;

		local_list_address = new list_item_type[item_num];
	}

	void clear_list()
	{
		for (size_t i = 0; i < local_total_size; i += local_item_size)
		{
			local_list_address[i / local_item_size] = 0;
		}
	}

	void add_item(list_item_type item)
	{
		for (size_t i = 0; i < local_total_size; i += local_item_size)
		{
			if (local_list_address[i / local_item_size] != 0)
				continue;

			local_list_address[i / local_item_size] = item;
			break;
		}
	}

	list_item_type get_delete()
	{
		for (size_t i = 0; i < local_total_size; i += local_item_size)
		{
			if (local_list_address[i / local_item_size] == 0)
				continue;

			list_item_type curritem = local_list_address[i / local_item_size];
			local_list_address[i / local_item_size] = 0;

			return curritem;
		}
	}
};