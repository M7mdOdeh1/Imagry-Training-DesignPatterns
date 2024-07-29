#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Observer Interface
class Observer {
public:
    virtual void update(const std::string& news) = 0;
    virtual ~Observer() {}
};

// Subject Interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() {}
};

// Concrete Subject
class NewsAgency : public Subject {
    std::vector<Observer*> observers;
    std::string latestNews;
public:
    void setNews(const std::string& news) {
        latestNews = news;
        notify();
    }
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }
    void detach(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notify() override {
        for (Observer* observer : observers) {
            observer->update(latestNews);
        }
    }
};

// Concrete Observer
class Subscriber : public Observer {
    std::string name;
public:
    Subscriber(const std::string& name) : name(name) {}
    void update(const std::string& news) override {
        std::cout << name << " received news update: " << news << std::endl;
    }
};

int main() {
    NewsAgency agency;
    Subscriber subscriber1("Alice");
    Subscriber subscriber2("Bob");

    agency.attach(&subscriber1);
    agency.attach(&subscriber2);

    agency.setNews("New product launch!");

    agency.detach(&subscriber1);
    agency.setNews("Stock prices soaring!");

    return 0;
}

