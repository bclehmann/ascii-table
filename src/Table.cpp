
#include "Table.h"
#include <sstream>
#include <iomanip>

std::string fill_string(char c, size_t n) {
	std::string s;
	for (int i = 0; i < n; i++)
		s += c;

	return s;
}

namespace ascii_table {
	std::stringstream Table::get_row_stream(Row& row, std::string header_rule, std::vector<size_t> true_widths, bool is_header) {
		std::stringstream stream;

		for (int i = 0; i < colspec.size(); i++) {
			stream << '|';
			std::string padding;
			for (int j = 0; j < colspec[i].padding; j++) {
				padding += ' ';
			}

			alignment align = is_header ? alignment::left : colspec[i].align;

			switch (align) {
				case alignment::center: {
					size_t space = true_widths[i] - row[i].size();
					size_t offset = space / 2;
					std::string offset_str = fill_string(' ', offset);

					stream << offset_str << row[i] << offset_str;

					if (offset * 2 < space) {
						stream << ' ';
					}
					break;
				}
				case alignment::left:
					stream << std::left;
					stream << padding << std::setw(true_widths[i] - colspec[i].padding) << row[i];
					break;
				case alignment::right:
					stream << std::right;
					stream << std::setw(true_widths[i] - colspec[i].padding) << row[i] << padding;
					break;
			}

			stream << std::left;
		}
		stream << "|\n";
		stream << header_rule << '\n';

		return stream;
	}

	std::stringstream Table::get_header_rule(std::vector<size_t> widths) {
		std::stringstream stream;

		for (int i = 0; i < widths.size(); i++) {
			stream << '+';
			for (int j = 0; j < widths[i]; j++) {
				stream << '-';
			}
		}

		stream << '+';

		return stream;
	}

	Table::Table(std::vector<ColumnInfo> colspec)
			: colspec(colspec) {

	}

	void Table::set_column_info(std::vector<ColumnInfo> colspec) {
		this->colspec = colspec;
	}

	void Table::set_rows(std::vector<Row> rows) {
		this->rows = rows;
	}

	void Table::add_row(Row row) {
		this->rows.push_back(row);
	}

	std::vector<size_t> Table::get_true_column_widths() {
		std::vector<size_t> widths;
		for (int i = 0; i < colspec.size(); i++) {
			size_t max_row_width = 0;
			for (int j = 0; j < rows.size(); j++) {
				max_row_width = std::max(max_row_width, rows[j][i].size());
			}

			widths.push_back(std::max(colspec[i].width, max_row_width) + 2 * colspec[i].padding);
		}

		return widths;
	}


	std::stringstream Table::get_table_stream() {
		std::stringstream stream;
		stream << std::left;

		std::vector<size_t> true_widths = get_true_column_widths();
		std::string header_rule = get_header_rule(true_widths).str();

		auto iter = rows.begin();

		stream << header_rule << '\n';

		if(has_header){
			stream << get_row_stream(*iter, header_rule, true_widths, true).str(); // For some reason you cannot append stringstreams to eachother
			iter++;
		}

		stream << header_rule << '\n';

		for (; iter != rows.end(); iter++) {
			stream << get_row_stream(*iter, header_rule, true_widths).str();
		}

		return stream;
	}

	std::string Table::get_table() {
		return get_table_stream().str();
	}




}