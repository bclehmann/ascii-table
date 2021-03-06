#ifndef ASCII_TABLE_TABLE_H
#define ASCII_TABLE_TABLE_H

#include <vector>
#include <sstream>
#include "column_info.h"
#include "string_row.h"

namespace ascii_table {
	 class table {
	public:
		table(std::vector<column_info> colspec);
		void set_column_info(std::vector<column_info> colspec);
		void set_rows(std::vector<string_row> rows);
		void add_row(string_row row);
		std::stringstream get_table_stream();
		std::string get_table();
		std::vector<size_t> get_true_column_widths();
	private:
		std::vector<column_info> colspec;
		std::vector<string_row> rows;
	 };

}


#endif //ASCII_TABLE_TABLE_H
