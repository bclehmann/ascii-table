
#ifndef ASCII_TABLE_ROWBASE_H
#define ASCII_TABLE_ROWBASE_H

#include <string>

namespace ascii_table {
	class RowBase {
	public:
		virtual std::string get_item(int i) = 0;
		virtual size_t size() = 0;
	};
}
#endif //ASCII_TABLE_ROWBASE_H
