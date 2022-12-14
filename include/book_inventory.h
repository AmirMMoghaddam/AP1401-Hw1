#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
namespace book
{
    struct Book
    {
        std::string title;         // title of the book
        std::string author;        // author of the book
        float cost;                // cost of the book
        std::string isbn;          // a unique string assigned to each book
        std::string language_code; // language of the book
        int num_pages;             // number of pages
        std::string publisher;     // publisher of the book
        int count;                 // how many books left in the inventory
    };
    using Books = std::vector<Book>;
    Books read_database(std::string filepath);
    std::string search(const Books &inventory, std::string title);
    bool order(Books &inventory, Books &shopinglist, std::string isbn);
    double get_receipt(const Books &shopinglist); // complete the print

}
