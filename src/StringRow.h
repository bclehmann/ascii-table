
#ifndef ASCII_TABLE_TESTS_STRINGROW_H
#define ASCII_TABLE_TESTS_STRINGROW_H

#include <vector>
#include <string>

namespace ascii_table{
	class StringRow{
	public:
		StringRow(std::vector<std::string> items)
		: items(items)
		{

		}
		std::vector<std::string> items;
	};
}

#endif //ASCII_TABLE_TESTS_STRINGROW_H
