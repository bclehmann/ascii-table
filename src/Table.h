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
		void first_row_header(bool enable){
			has_header = enable;
		}
	private:
		std::stringstream get_row_stream(Row& row, std::string header_rule, std::vector<size_t> true_widths, bool is_header = false);
		std::stringstream get_header_rule(std::vector<size_t> widths);
		std::vector<ColumnInfo> colspec;
		std::vector<Row> rows;
		bool has_header = false;
	 };

}


#endif //ASCII_TABLE_TABLE_H
