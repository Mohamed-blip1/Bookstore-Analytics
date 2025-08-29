#pragma once
#include <iostream>

std::string trim(const std::string &str, char target = ' ')
{
    size_t start = str.find_first_not_of(target);
    size_t end = str.find_last_not_of(target);

    if (start == std::string::npos)
        return "";

    return str.substr(start, end - start + 1);
}

namespace utils
{
    inline std::string get_title_from_user()
    {
        std::string title;
        do
        {
            std::cout << "\nEnter a Title   : ";
            std::getline(std::cin, title);
            title = trim(title);
            if (title.empty())
                std::cout << "Input cannot be empty. Please try again.\n";

        } while (title.empty());

        return title;
    }
    inline std::string get_author_from_user()
    {
        std::string author;
        do
        {
            std::cout << "\nEnter a author  : ";
            std::getline(std::cin, author);
            author = trim(author);
            if (author.empty())
                std::cout << "Input cannot be empty. Please try again.\n";

        } while (author.empty());

        return author;
    }
    inline std::string get_category_from_user()
    {
        std::string category;

        do
        {
            std::cout << "\nEnter a category: ";
            std::getline(std::cin, category);
            category = trim(category);
            if (category.empty())
                std::cout << "Input cannot be empty. Please try again.\n";

        } while (category.empty());

        return category;
    }

    void menu()
    {
        std::cout << "\n===== Library Menu =====\n";
        std::cout << "● 1 - Add Book\n";
        std::cout << "● 2 - Search Book\n";
        std::cout << "● 3 - List Books By Authors\n";
        std::cout << "● 4 - Borrow Book\n";
        std::cout << "● 5 - List All Books\n";
        std::cout << "● 6 - Remove Book\n";
        std::cout << "● 0 - Exit\n";
    }

    size_t get_valid_number_from_user()
    {
        size_t number;
        while (true)
        {
            std::cout << "> ";
            std::cin >> number;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "\nPlease Enter A Valid Number: ";
            }
            else
            {
                std::cin.ignore(1000, '\n');
                return number;
            }
        }
    }

}