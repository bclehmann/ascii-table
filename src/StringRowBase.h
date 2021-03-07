
#ifndef ASCII_TABLE_TESTS_STRINGROWBASE_H
#define ASCII_TABLE_TESTS_STRINGROWBASE_H

#include "RowBase.h"
#include <utility>
#include <vector>
#include <string>

namespace ascii_table{
	class StringRowBase : public RowBase {
	public:
		StringRowBase() = default;
		explicit StringRowBase(std::vector<std::string> items)
		: items(std::move(items))
		{

		}
		std::string get_item(int i) override{
			return items[i];
		}
		size_t size() override{
			return items.size();
		}
		std::vector<std::string> items;
	};
}

#endif //ASCII_TABLE_TESTS_STRINGROWBASE_H
