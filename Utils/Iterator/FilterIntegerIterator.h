
#pragma once

#include <cstddef>
#include <functional>

class FilterIntegerIterator
{
private:
    const int* data_;
    std::size_t size_;
    std::size_t index_;
    std::function<bool(int)> predicate_;

    void skipNonMatching()
    {
        while (index_ < size_ && !predicate_(data_[index_]))
        {
            ++index_;
        }
    }

public:
    FilterIntegerIterator(
        const int* data,
        std::size_t size,
        std::function<bool(int)> predicate,
        std::size_t index
    )
        : data_(data), size_(size),
          index_(index), predicate_(predicate)
    {
        skipNonMatching();
    }

    const int& operator*() const
    {
        return data_[index_];
    }

    FilterIntegerIterator& operator++()
    {
        if (index_ < size_)
            ++index_;

        skipNonMatching();
        return *this;
    }

    bool operator==(const FilterIntegerIterator& other) const
    {
        return data_ == other.data_ &&
               index_ == other.index_;
    }

    bool operator!=(const FilterIntegerIterator& other) const
    {
        return !(*this == other);
    }
};

class FilterIntegerIteratorBuilder
{
private:
    const int* data_;
    std::size_t size_;
    std::function<bool(int)> predicate_;

public:
    FilterIntegerIteratorBuilder(
        const int* data,
        std::size_t size,
        std::function<bool(int)> predicate
    )
        : data_(data), size_(size), predicate_(predicate)
    {
    }

    FilterIntegerIterator begin() const
    {
        return FilterIntegerIterator(data_, size_, predicate_, 0);
    }

    FilterIntegerIterator end() const
    {
        return FilterIntegerIterator(data_, size_, predicate_, size_);
    }
};
