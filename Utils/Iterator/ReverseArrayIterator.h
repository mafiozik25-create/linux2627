
#pragma once

#include <cstddef>

class ReverseArrayIterator
{
private:
    const int* data_;
    std::ptrdiff_t index_;

public:
    ReverseArrayIterator(const int* data, std::ptrdiff_t index)
        : data_(data), index_(index)
    {
    }

    const int& operator*() const
    {
        return data_[index_];
    }

    ReverseArrayIterator& operator++()
    {
        --index_;
        return *this;
    }

    bool operator==(const ReverseArrayIterator& other) const
    {
        return data_ == other.data_ && index_ == other.index_;
    }

    bool operator!=(const ReverseArrayIterator& other) const
    {
        return !(*this == other);
    }
};

class ReverseArrayIteratorBuilder
{
private:
    const int* data_;
    std::size_t size_;

public:
    ReverseArrayIteratorBuilder(const int* data, std::size_t size)
        : data_(data), size_(size)
    {
    }

    ReverseArrayIterator begin() const
    {
        return ReverseArrayIterator(
            data_,
            size_ == 0 ? -1 : static_cast<std::ptrdiff_t>(size_ - 1)
        );
    }

    ReverseArrayIterator end() const
    {
        return ReverseArrayIterator(data_, -1);
    }
};
