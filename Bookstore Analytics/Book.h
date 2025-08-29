#pragma once
#include <iostream>

class Book
{
public:
    Book(std::string title, std::string author, std::string category)
        : title_(std::move(title)), author_(std::move(author)), category_(std::move(category)) {}

    const std::string &get_title() const noexcept { return title_; }
    const std::string &get_author() const noexcept { return author_; }
    const std::string &get_category() const noexcept { return category_; }

    bool operator==(const Book &other) const noexcept { return title_ == other.title_ &&
                                                               author_ == other.author_ &&
                                                               category_ == other.category_; }
    bool operator!=(const Book &other) const noexcept { return !(*this == other); }

    friend std::ostream &operator<<(std::ostream &os, const Book &book) noexcept
    {
        os << "\nTitle   : " << book.title_ << "\n"
           << "Author  : " << book.author_ << "\n"
           << "Category: " << book.category_ << "\n";

        return os;
    }

private:
    std::string title_;
    std::string author_;
    std::string category_;
};