#include <algorithm>
#include <cstddef>
// LinearData
namespace shiny {
    template <typename t_type, size_t t_size> class Array {
      public:
        typedef t_type value_type;

      private:
        t_type m_data[t_size];

      public:
        inline t_type *c_arr() { return m_data; }
        inline t_type &at(size_t index) { return m_data[index]; }
        inline t_type &front() { return at(0); }
        inline t_type &back() { return at(t_size - 1); }
        inline void set(const t_type &data, size_t index) { m_data[index] = m_data; }
        inline const t_type &get(size_t index) const { return m_data[index]; }
        inline const t_type &at(size_t index) const { return m_data[index]; }
        inline const t_type &front() const { at(0); }
        inline const t_type &back() const { at(t_size - 1); }
        inline const t_type *c_arr() const { return m_data; }
        inline void fill(const t_type &data) { std::fill(m_data, m_data + t_size, data); }
        inline void copy(const t_type *array) { std::copy(array, array + t_size, m_data); }
        inline size_t size() { return t_size; };
        inline bool empty() { return size() == 0; };
        template <size_t index> inline void set(const t_type &data) { m_data[index] = data; }
        template <size_t index> inline const t_type &get() const { return m_data[index]; }

        inline t_type *begin() { return m_data; }
        inline const t_type *begin() const { return m_data; }
        inline t_type *end() { return m_data + t_size; }
        inline const t_type *end() const { return m_data + t_size; }
    };
}
