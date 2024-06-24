#include <concepts>
#include <cstddef>

namespace shiny {
    template <typename DataStructure>
    concept LinearDataStructure = requires(const DataStructure &constDataStructure, DataStructure &dataStructure, size_t index, typename DataStructure::value_type data) {
        typename DataStructure::value_type;
        { dataStructure.at(index) } -> std::convertible_to<typename DataStructure::value_type &>;
        { constDataStructure.at(index) } -> std::convertible_to<const typename DataStructure::value_type>;
        { dataStructure.front() } -> std::convertible_to<typename DataStructure::value_type &>;
        { constDataStructure.front() } -> std::convertible_to<const typename DataStructure::value_type>;
        { dataStructure.back() } -> std::convertible_to<typename DataStructure::value_type &>;
        { constDataStructure.back() } -> std::convertible_to<const typename DataStructure::value_type>;
        { dataStructure.set(data, index) } -> std::same_as<void>;
        { constDataStructure.get(index) } -> std::convertible_to<typename DataStructure::value_type>;
        { dataStructure.fill(data) } -> std::same_as<void>;
        { constDataStructure.size() } -> std::convertible_to<size_t>;
        { constDataStructure.empty() } -> std::same_as<bool>;
    };
}
