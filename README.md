# ascii-table

A simple C++ 14 library to create text-based tables. Supports rows made of `std::string` as well as an interface to create your own row types.

# Basics

```cpp
ascii_table::ColumnInfo col1(20); // Minimum width of 20
ascii_table::ColumnInfo col2(20, ascii_table::alignment::right);
ascii_table::ColumnInfo col3(0, ascii_table::alignment::center);
std::vector<ascii_table::ColumnInfo> colspec = {col1, col2, col3};

ascii_table::Table table(colspec);
table.first_row_header(true); // Turns on table header
table.add_row(ascii_table::StringRow({"Column 1", "Column 2", "Column 3"}));
table.add_row(ascii_table::StringRow({"Ben", "Steve", "Bob"}));
table.add_row(ascii_table::StringRow({"Benjamin", "Stephen", "Robert"}));
table.add_row(ascii_table::StringRow({"Benjamin Smith", "Stephen Smith", "Robert Smith"}));
table.add_row(ascii_table::StringRow({"Benjamin Smithson", "Stephen Smithson", "Robert Smithson"}));

std::cout << table.get_table();
```

Creates this table:

```
+----------------------+----------------------+-----------------+
| Column 1             | Column 2             | Column 3        |
+----------------------+----------------------+-----------------+
+----------------------+----------------------+-----------------+
| Ben                  |                Steve |       Bob       |
+----------------------+----------------------+-----------------+
| Benjamin             |              Stephen |     Robert      |
+----------------------+----------------------+-----------------+
| Benjamin Smith       |        Stephen Smith |  Robert Smith   |
+----------------------+----------------------+-----------------+
| Benjamin Smithson    |     Stephen Smithson | Robert Smithson |
+----------------------+----------------------+-----------------+
```

# Linking and Compilation

The `CMakeLists.txt` here [tests/CMakeLists.txt](https://github.com/bclehmann/ascii-table/blob/master/tests/CMakeLists.txt) should help anyone trying to link this with their own project.

This library was compiled with GCC with the C++ 14 standard, however it should build on any compiler with C++ 14 support. Compilation was done with this CMake file [src/CMakeLists.txt](https://github.com/bclehmann/ascii-table/blob/master/src/CMakeLists.txt)

# Creating your own row class

Here is the code for `StringRow`, note it is just a resource handle for `StringRowBase` which sets `handle` to an `std::shared_ptr<StringRowBase>`.
```cpp
class StringRow : public Row {
public:
	StringRow() {
		handle = std::make_shared<StringRowBase>();
	}

	explicit StringRow(std::vector<std::string> items)
	: StringRow()
	{
		dynamic_cast<StringRowBase*>(handle.get())->items = items;
	}
};
```

`handle` is a protected field that the base class `Row` uses internally. This is necessary because `std::vector` cannot hold abstract types, only pointers to them (or concrete wrapper classes). `StringRowBase` also adds a constructor for initializing the `items` field of `StringRowBase`, but this a convenience not a necessity.


If one looks at `StringRowBase` it's pretty compact:

```cpp
class StringRowBase : public RowBase {
public:
	StringRowBase() = default;
	explicit StringRowBase(std::vector<std::string> items)
	: items(std::move(items))
	{

	}
	std::string get_item(int i) override{
		return items[i];
	}
	size_t size() override{
		return items.size();
	}
	std::vector<std::string> items;
};
```

As you can see, this class merely provides a method `get_item` to provide the string output of a column and `size()` to provide the number of items in the row.
