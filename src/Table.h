#ifndef ASCII_TABLE_TABLE_H
#define ASCII_TABLE_TABLE_H

#include "ColumnInfo.h"
#include "StringRow.h"
#include <vector>
#include <sstream>


namespace ascii_table {
	class Table {
	public:
		Table(std::vector<ColumnInfo> colspec);
		void set_column_info(std::vector<ColumnInfo> colspec);
		void set_rows(std::vector<StringRow> rows);
		void add_row(StringRow row);
		std::stringstream get_table_stream();
		std::string get_table();
		std::vector<size_t> get_true_column_widths();
	private:
		std::vector<ColumnInfo> colspec;
		std::vector<StringRow> rows;
	 };

}


#endif //ASCII_TABLE_TABLE_H
