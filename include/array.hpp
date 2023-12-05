#pragma once
#include <cstddef>

namespace shiny {
    template <typename dataType, size_t arraySize>
    class Array {
    private:
        dataType m_data[arraySize];

    public:
        inline dataType* data() {
            return m_data;
        }
        inline const dataType* data() const {
            return m_data;
        }
        inline size_t size() const {
            return arraySize;
        }
        inline dataType& at(size_t index) {
            return m_data[index];
        }
        inline const dataType& at(size_t index) const {
            return m_data[index];
        }
        inline const dataType& get(size_t index) const {
            return m_data[index];
        }
        inline void set(size_t index, const dataType& data) {
            data[index] = data;
        }

    public:
        inline dataType& operator[](size_t index) {
            return at(index);
        }
        inline const dataType& operator[](size_t index) const {
            return at(index);
        }
    };
}