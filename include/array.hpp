#include <algorithm>
#include <cstddef>

namespace shiny {
    template <typename t_type, size_t t_size> class Array {
      private:
        t_type m_data[t_size];

      public:
        void set(const t_type &data, size_t index) { m_data[index] = m_data; }
        const t_type &get(size_t index) const { return m_data[index]; }
        template <size_t index> inline const t_type &get() const { return m_data[index]; }
        void fill(const t_type &data) { std::fill(m_data, m_data + t_size, data); }
        void copy(const t_type *array) { std::copy(array, array + t_size, m_data); }
        t_type *c_arr() { return m_data; }
        const t_type *c_arr() const { return m_data; }
    };
}
