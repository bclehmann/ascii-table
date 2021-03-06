#include <iostream>
#include <vector>
#include "../src/table.h"

int main(int argc, char* argv[]){
	std::vector<ascii_table::column_info> colspec = {ascii_table::column_info(20), ascii_table::column_info(30, ascii_table::alignment::right), ascii_table::column_info(0, ascii_table::alignment::center)};
	ascii_table::table table(colspec);
	table.add_row(ascii_table::string_row({"Ben", "Steve", "Bob"}));
	table.add_row(ascii_table::string_row({"Benjamin", "Stephen", "Robert"}));
	table.add_row(ascii_table::string_row({"Benjamin Smith", "Stephen Smith", "Robert Smith"}));
	table.add_row(ascii_table::string_row({"Benjamin Smithson", "Stephen Smithson", "Robert Smithson"}));

	std::cout << table.get_table();

}