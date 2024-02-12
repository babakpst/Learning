#include <algorithm>
#include <iostream>
#include <vector>

// Forward declaration of Publisher class
class Publisher;

// Subscriber Interface/observer
class Subscriber
{
 public:
  virtual void update(Publisher* publisher) = 0;
};

// Publisher Class / Subject
class Publisher
{
 private:
  std::vector<Subscriber*> subscribers;
  int state;

 public:
  void attach(Subscriber* subscriber) { subscribers.push_back(subscriber); }  // register subscriber/observer

  void detach(Subscriber* subscriber)  // remove subscriber/observer
  {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
  }

  void notify()  // notify all subscribers/observers
  {
    for (Subscriber* subscriber : subscribers)
    {
      subscriber->update(this);
    }
  }

  void setState(int value)
  {
    state = value;
    notify();
  }

  int getState() { return state; }
};

// Concrete Subscriber/observer
class ConcreteSubscriber : public Subscriber
{
 public:
  void update(Publisher* publisher) override
  {
    std::cout << "State of publisher is: " << publisher->getState() << "\n";
  }
};

// concrete Subject
int main()
{
  Publisher publisher;
  ConcreteSubscriber subscriber;

  publisher.attach(&subscriber);
  publisher.setState(123);  // The subscriber gets notified of state change

  return 0;
}
