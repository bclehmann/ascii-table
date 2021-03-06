#include <iostream>
#include <vector>
#include "../src/Table.h"

int main(int argc, char* argv[]){
	ascii_table::ColumnInfo col1(20);
	ascii_table::ColumnInfo col2(20, ascii_table::alignment::right);
	ascii_table::ColumnInfo col3(0, ascii_table::alignment::center);
	std::vector<ascii_table::ColumnInfo> colspec = {col1, col2, col3};

	ascii_table::Table table(colspec);
	table.add_row(ascii_table::StringRow({"Ben", "Steve", "Bob"}));
	table.add_row(ascii_table::StringRow({"Benjamin", "Stephen", "Robert"}));
	table.add_row(ascii_table::StringRow({"Benjamin Smith", "Stephen Smith", "Robert Smith"}));
	table.add_row(ascii_table::StringRow({"Benjamin Smithson", "Stephen Smithson", "Robert Smithson"}));

	std::cout << table.get_table();
}