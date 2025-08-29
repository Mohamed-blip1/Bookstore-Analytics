#include <iostream>
#include "Library.h"

int main()
{

    Library library;
    size_t choice;

    do
    {
        utils::menu();
        choice = utils::get_valid_number_from_user();

        switch (choice)
        {
        case 0:
            // Exit
            std::cout << "Goodby!\n";
            break;

        case 1:
            // Add book
            {
                auto title = utils::get_title_from_user();
                auto author = utils::get_author_from_user();
                auto category = utils::get_category_from_user();
                library.add_book(title, author, category);
                break;
            }
        case 2:
            // Search by parti-title
            if (library.search_by_title(utils::get_title_from_user()).empty())
                std::cout << "No Book Found!\n";
            break;

        case 3:
            // List Books By Authors
            if (!library.list_authors())
                std::cout << "Library Is Empty!\n";

            break;

        case 5:
            // List All Books
            if (!library.list_books())
                std::cout << "Library Is Empty!\n";

            break;

        case 6:
            // Remove by Parti-title
            {
                std::set<int> indexes = library.search_by_title(utils::get_title_from_user());

                if (indexes.empty())
                {
                    std::cout << "No Book Found!\n";
                    break;
                }

                std::cout << "\nSelect The Book Number You Want To Remove: ";
                size_t num = utils::get_valid_number_from_user();

                if (!library.remove(num, indexes))
                    std::cout << "There Is No Book With This Number.!\n";
                else
                    std::cout << "The Book Has Been Removed!\n";

                break;
            }

        default:
            // Choice(out-of-range)
            std::cout << "'" << choice << "' Is Not A Choice!\n";
        }
    } while (choice);

    return 0;
}