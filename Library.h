#include "Book.h"
#include "Utils.h"
#include <vector>
#include <set>
#include <algorithm>

struct CompareByAuthorNameLength
{
    bool operator()(const std::string &a, const std::string &b) const
    {
        return (a.length() == b.length()) ? a < b : a.length() < b.length();
    }
};

class Library
{

public:
    void add_book(std::string title, std::string author, std::string category)
    {
        auto it = track_.lower_bound(author);

        books_.emplace_back(std::move(title), std::move(author), std::move(category));
        track_.emplace_hint(it, books_.back().get_author());
    }

    bool list_books() const noexcept
    {
        if (books_.empty())
            return false;

        int index = 1;
        for (const auto &book : books_)
            std::cout << "\nBook #" << index++
                      << book;

        return true;
    }

    bool list_authors() const noexcept
    {
        if (track_.empty())
            return false;

        int index = 1;
        for (const auto &book : track_)
            std::cout << "\nBook #" << index++ << "\n"
                      << "Author: " << book << "\n";

        return true;
    }

    std::set<int> search_by_title(std::string parti_title)
    {
        std::set<int> indexes;
        std::string lower_parti = to_lower(parti_title);

        for (auto it = books_.begin(); it != books_.end(); ++it)
        {
            std::string lower_title = to_lower(it->get_title());

            if (lower_title.find(lower_parti) != std::string::npos)
            {
                int n = it - books_.begin();
                auto i = indexes.lower_bound(n);
                indexes.emplace_hint(i, n);

                std::cout << "\nBook #" << n + 1
                          << books_[n];
            }
        }

        return indexes;
    }

    bool remove(size_t n, const std::set<int> indexes)
    {
        if (n == 0 || indexes.find(n - 1) == indexes.end())
            return false;

        n--;
        std::string author = books_[n].get_author();

        if (books_[n] != books_.back())
            books_[n] = books_.back();

        books_.pop_back();

        auto it = track_.find(author);
        if (it == track_.end())
            return false;

        track_.erase(it);

        return true;
    }

private:
    std::string to_lower(const std::string &str)
    {
        std::string lower = str;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        return lower;
    }

private:
    std::vector<Book> books_;
    std::multiset<std::string, CompareByAuthorNameLength> track_;
};