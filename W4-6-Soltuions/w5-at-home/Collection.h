// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <ostream>

namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string m_name;
		T* m_items = nullptr;
		size_t m_cnt = 0;

		void (*onItemAdded)(const Collection&, const T&) = nullptr;
	public:
		Collection(std::string name) { this->m_name = name; }
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		~Collection()
		{
			delete[] m_items;
		}

		void setObserver(void (*observer)(const Collection&, const T&))
		{
			this->onItemAdded = observer;
		}
		const std::string& name() const { return m_name; }
		size_t size() const { return m_cnt; }

		Collection& operator+=(const T& item)
		{
			for (auto i = 0u; i < m_cnt; ++i)
				if (this->m_items[i].title() == item.title())
					return *this;

			// item not in the collection
			T* tmp = new T[m_cnt + 1];
			for (auto i = 0u; i < m_cnt; ++i)
				tmp[i] = this->m_items[i];
			tmp[m_cnt] = item;

			delete[] m_items;
			m_items = tmp;
			++m_cnt;

			if (onItemAdded != nullptr)
				onItemAdded(*this, m_items[m_cnt - 1]);
			return *this;
		}

		T& operator[](size_t idx) const
		{
			if (idx >= m_cnt)
			{
				std::string msg = "Bad index [";
				msg += std::to_string(idx);
				msg += "]. Collection has [";
				msg += std::to_string(m_cnt);
				msg += "] items.";
				throw std::out_of_range(msg);
			}
			return this->m_items[idx];
		}

		T* operator[](std::string title) const
		{
			for (size_t i = 0; i < m_cnt; ++i)
				if (m_items[i].title() == title)
					return &(m_items[i]);

			return nullptr;
		}

	};
	template<typename T>
	std::ostream& operator<<(std::ostream& out, const Collection<T>& collection)
	{
		for (auto i = 0u; i < collection.size(); ++i)
			out << collection[i];
		return out;
	}
}
#endif