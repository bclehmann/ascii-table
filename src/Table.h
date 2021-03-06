#ifndef ASCII_TABLE_TABLE_H
#define ASCII_TABLE_TABLE_H

#include "ColumnInfo.h"
#include "Row.h"
#include <vector>
#include <sstream>


namespace ascii_table {
	class Table {
	public:
		explicit Table(std::vector<ColumnInfo> colspec);
		void set_column_info(std::vector<ColumnInfo> colspec);
		void set_rows(std::vector<Row> rows);
		void add_row(Row row);
		std::stringstream get_table_stream();
		std::string get_table();
		std::vector<size_t> get_true_column_widths();
	private:
		std::vector<ColumnInfo> colspec;
		std::vector<Row> rows;
	 };

}


#endif //ASCII_TABLE_TABLE_H
