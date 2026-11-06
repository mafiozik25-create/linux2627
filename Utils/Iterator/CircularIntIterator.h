
#pragma once

#include <cstddef>
#include <stdexcept>

class CircularIntIteratorBuilder
{
private:
    const int* data_;
    std::size_t size_;
    std::size_t index_;

public:
    CircularIntIteratorBuilder(const int* data, std::size_t size)
        : data_(data), size_(size), index_(0)
    {
    }

    const int& operator*() const
    {
        if (size_ == 0)
            throw std::out_of_range("Empty circular iterator");

        return data_[index_];
    }

    CircularIntIteratorBuilder& operator++()
    {
        if (size_ != 0)
            index_ = (index_ + 1) % size_;

        return *this;
    }
};
