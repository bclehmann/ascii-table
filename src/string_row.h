
#ifndef ASCII_TABLE_TESTS_STRING_ROW_H
#define ASCII_TABLE_TESTS_STRING_ROW_H

namespace ascii_table{
	class string_row{
	public:
		string_row(std::vector<std::string> items)
		: items(items)
		{

		}
		std::vector<std::string> items;
	};
}

#endif //ASCII_TABLE_TESTS_STRING_ROW_H
