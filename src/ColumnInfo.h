
#ifndef ASCII_TABLE_COLUMN_INFO_H
#define ASCII_TABLE_COLUMN_INFO_H

#include <cstddef>

namespace ascii_table {
	enum class alignment{
		left,
		right,
		center
	};

	struct ColumnInfo {
	public:
		ColumnInfo(size_t width, alignment align = alignment::left, size_t padding = 1)
		: width(width)
		, align(align)
		, padding(padding)
		{

		}
		size_t width = 0;
		size_t padding = 1;
		alignment align = alignment::left;
	};
}


#endif //ASCII_TABLE_COLUMN_INFO_H
