#include <iostream>
#include <string>

using namespace std;

class Logger
{

private:
    // Private Constructor --> cannot be accessed outside the class implementation
    Logger() {}

    // These two methods are kept from being implemented anywhere so that no copies can be made
    Logger(Logger const &) = delete;
    void operator=(Logger const &) = delete;

public:
    // Returns the Logger's reference (only one is to exist)
    static Logger &getInstance()
    {
        static Logger instance; // Singleton instance --> static will make it so it is created once (on first call)
        return instance;
    }

    // This method logs the input msg
    void log(const string &message)
    {
        cout << message << endl;
    }
};

int main()
{
    // Gets the instance and logs the message inmediately
    Logger::getInstance().log("Testing!");
    return 0;
}