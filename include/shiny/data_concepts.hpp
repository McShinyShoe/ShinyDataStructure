#include <concepts>
#include <cstddef>

namespace shiny {
    template <typename DataStructure>
    concept LinearDataStructure = requires(DataStructure dataStructure, size_t index, typename DataStructure::value_type data) {
        typename DataStructure::value_type;
        { dataStructure.at(index) } -> std::convertible_to<typename DataStructure::value_type>;
        { dataStructure.front() } -> std::convertible_to<typename DataStructure::value_type>;
        { dataStructure.back() } -> std::convertible_to<typename DataStructure::value_type>;
        { dataStructure.set(data, index) } -> std::same_as<void>;
        { dataStructure.get(index) } -> std::convertible_to<typename DataStructure::value_type>;
        { dataStructure.fill(data) } -> std::same_as<void>;
        { dataStructure.size() } -> std::convertible_to<size_t>;
        { dataStructure.empty() } -> std::same_as<bool>;
    };
}
