
#ifndef ASCII_TABLE_ROW_H
#define ASCII_TABLE_ROW_H

#include "RowBase.h"
#include "StringRowBase.h"
#include <string>
#include <memory>
#include <utility>

namespace ascii_table {
	class Row {
	public:
		Row() = default;

		explicit Row(RowBase* base) {
			handle = std::shared_ptr<RowBase>(base);
		}

		std::string operator[](std::size_t i) const {
			return handle->get_item(i);
		}

		size_t size(){
			return handle->size();
		}

	protected:
		 std::shared_ptr<RowBase> handle;
	};

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
}

#endif //ASCII_TABLE_ROW_H
