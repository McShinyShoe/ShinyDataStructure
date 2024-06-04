#include <algorithm>
#include <cstddef>
// LinearData
namespace shiny {
    template <typename t_type, size_t t_size> class Array {
      private:
        t_type m_data[t_size];

      public:
        // Class Methodes
        typedef t_type data_type;
        void set(const t_type &data, size_t index) { m_data[index] = m_data; }
        const t_type &get(size_t index) const { return m_data[index]; }
        template <size_t index> inline const t_type &get() const { return m_data[index]; }
        template <size_t index> inline void set(const t_type &data) { m_data[index] = data; }
        void fill(const t_type &data) { std::fill(m_data, m_data + t_size, data); }
        void copy(const t_type *array) { std::copy(array, array + t_size, m_data); }
        t_type *c_arr() { return m_data; }
        const t_type *c_arr() const { return m_data; }
        size_t size() { return t_size; };

        // Iterator>
        t_type *begin() { return m_data; }
        const t_type *begin() const { return m_data; }
        t_type *end() { return m_data + t_size; }
        const t_type *end() const { return m_data + t_size; }
    };
}
