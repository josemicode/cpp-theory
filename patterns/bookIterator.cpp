#include <iostream>

using namespace std;

/*
3. Patrón Iterador
TODO:
a) Considera la implementación de un iterador para una colección de libros en una biblioteca.
* Crea la clase Libro con las propiedades de: título, autor y año de publicación.
* Crea una clase Biblioteca que almacene una lista de libros.
* Implementa la interfaz de iterador con los métodos has_next() y next() para recorrer la lista de libros.
* Escribe un código de prueba que muestre cómo se puede recorrer la lista de libros utilizando el iterador.
 */

class Book
{
private:
    string title;
    string author;
    int year;

public:
    Book(string _title, string _author, int _year) : title(_title), author(_author), year(_year) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
};

class Iterator
{
public:
    virtual bool hasNext() const = 0;
    virtual Book *next() = 0;
};

class BookIterator : public Iterator
{
private:
    Book *books;
    size_t index;
    size_t size;

public:
    BookIterator(Book *_books, size_t _size) : books(_books), size(_size) {}

    bool hasNext() const override
    {
        return index < size;
    }

    Book *next() override
    {
        return &books[index++];
    }
};

int main()
{
    Book library[3] = {Book("Jujutsu Kaisen", "Gege Akutami", 2018), Book("Chainsaw Man", "Tatsuki Fujimoto", 2019), Book("Dragon Ball Z", "Akira Toriyama", 1986)};

    Iterator *it = new BookIterator(library, 3);
    while (it->hasNext())
    {
        Book *book = it->next();
        cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", Year: " << book->getYear() << endl;
    }

    // Free Memory
    delete it;
    return 0;
}
