#include <iostream>

using namespace std;
/*
4. Patrón Observador
TODO:
a) Considera la implementación de un sistema de notificación para una agencia de noticias. En
este ejercicio, se le pide que implemente el patrón de diseño Observador para notificar a los
suscriptores sobre las últimas noticias.
* Define una clase Agencia con métodos para agregar, eliminar y notificar a los observadores.
* Crea una clase concreta AgenciaNoticias que extienda la clase Agencia y tenga un método para publicar noticias.
* Define la clase abstracta Observador con un método update().
* Crea clases concretas de observadores para diferentes tipos de suscriptores (por ejemplo, suscriptor de correo electrónico, suscriptor de SMS).
* Escribe un código de prueba que muestre cómo los observadores reciben notificaciones cuando se publican noticias.
*/

#include <iostream>
#include <vector>
#include <string>

// Forward declaration of Observer class
class Observer;

// Subject class
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers(const std::string& news) = 0;
};

// Observer class
class Observer {
public:
    virtual void update(const string& news) = 0;
};

// Concrete Subject class
class NewsAgency : public Subject {
private:
    vector
    <Observer*> observers;
    string latestNews;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers(const std::string& news) override {
        latestNews = news;
        for (Observer* observer : observers) {
            observer->update(latestNews);
        }
    }

    void publishNews(const std::string& news) {
        notifyObservers(news);
    }
};

// Concrete Observer classes
class EmailSubscriber : public Observer {
public:
    void update(const std::string& news) override {
        std::cout << "Email: Received latest news - " << news << endl;
    }
};

class SMSSubscriber : public Observer {
public:
    void update(const std::string& news) override {
        std::cout << "SMS: Received latest news - " << news << endl;
    }
};

// Test code
int main() {
    NewsAgency agency;

    // Creating observers
    EmailSubscriber emailSubscriber;
    SMSSubscriber smsSubscriber;

    // Adding observers to the agency
    agency.addObserver(&emailSubscriber);
    agency.addObserver(&smsSubscriber);

    // Publishing news
    agency.publishNews("Breaking: New discovery in an underground lab!");

    // Removing an observer
    agency.removeObserver(&emailSubscriber);

    // Publishing more news
    agency.publishNews("Update: the virus has mutated...");

    return 0;
}