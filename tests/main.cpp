#include <iostream>
#include <vector>
#include "../src/Table.h"

int main(int argc, char* argv[]){
	std::vector<ascii_table::ColumnInfo> colspec = {ascii_table::ColumnInfo(20), ascii_table::ColumnInfo(30, ascii_table::alignment::right), ascii_table::ColumnInfo(0, ascii_table::alignment::center)};
	ascii_table::Table table(colspec);
	table.add_row(ascii_table::StringRow({"Ben", "Steve", "Bob"}));
	table.add_row(ascii_table::StringRow({"Benjamin", "Stephen", "Robert"}));
	table.add_row(ascii_table::StringRow({"Benjamin Smith", "Stephen Smith", "Robert Smith"}));
	table.add_row(ascii_table::StringRow({"Benjamin Smithson", "Stephen Smithson", "Robert Smithson"}));

	std::cout << table.get_table();

}