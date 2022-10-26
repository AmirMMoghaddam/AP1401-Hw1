#include "book_inventory.h"

using Books = std::vector<book::Book>;

Books book::read_database(std::string filepath)
{
    std::string line;
    std::ifstream inventory;
    inventory.open(filepath);
    if (!inventory)
    {
        throw std::runtime_error("the file path is not here");
    }
    size_t Lcounter{0};
    Books ListOfBooks;
    while (std::getline(inventory, line))
    {
        Book TempBook;
        std::vector<std::string> lineSep;
        size_t place{line.find(",")};
        line.erase(0, place + 1);
        place = line.find(",");
        while (place <= line.length())
        {
            lineSep.push_back(line.substr(0, place));
            line.erase(0, place + 1);
            place = line.find(",");
        }
        lineSep.push_back(line);
        TempBook.count = std::stoi(lineSep[7]);
        TempBook.publisher = lineSep[6];
        TempBook.num_pages = std::stoi(lineSep[5]);
        TempBook.language_code = lineSep[4];
        TempBook.isbn = lineSep[3];
        TempBook.cost = std::stof(lineSep[2]);
        TempBook.author = lineSep[1];
        TempBook.title = lineSep[0];
        ListOfBooks.push_back(TempBook);
    }
    return ListOfBooks;
}

std::string book::search(Books inventory, std::string title)
{
    std::string isbn{"none"};
    for (auto Tempbook : inventory)
    {
        if (Tempbook.title == title)
        {
            isbn = Tempbook.isbn;
        }
    }
    return isbn;
}

bool book::order(Books &inventory, Books &shopinglist, std::string isbn)
{
    if (isbn == "none")
    {
        return false;
    }
    size_t len{inventory.size()};
    for (size_t i{0}; i < len; i++)
    {
        if (inventory[i].isbn == isbn)
        {
            shopinglist.push_back(inventory[i]);
            inventory[i].count--;
        }
    }
    return true;
}

double get_receipt(Books shopinglist)
{
    // complete the prints
}