#include <algorithm>
#include <iostream>
#include <vector>

// Forward declaration of Publisher class
class Publisher;

// Subscriber Interface
class Subscriber
{
 public:
  virtual void update(Publisher* publisher) = 0;
};

// Publisher Class
class Publisher
{
 public:
  void attach(Subscriber* subscriber) { subscribers.push_back(subscriber); }

  void detach(Subscriber* subscriber)
  {
    subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), subscriber), subscribers.end());
  }

  void notify()
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

 private:
  std::vector<Subscriber*> subscribers;
  int state;
};

// Concrete Subscriber
class ConcreteSubscriber : public Subscriber
{
 public:
  void update(Publisher* publisher) override
  {
    std::cout << "State of publisher is: " << publisher->getState() << "\n";
  }
};

int main()
{
  Publisher publisher;
  ConcreteSubscriber subscriber;

  publisher.attach(&subscriber);
  publisher.setState(123);  // The subscriber gets notified of state change

  return 0;
}
