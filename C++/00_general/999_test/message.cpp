
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ==================================================
class Message {
public:
  int order;
  string txt;

  Message() {}
  const string &get_text() { return txt; }
  bool operator<(const Message &a) {
    bool ans;
    order < a.order ? ans = true : ans = false;
    return ans;
  }
};

// ==================================================
class MessageFactory {
public:
  static int cnt;
  Message a;

  MessageFactory() {}
  Message create_message(const string &text) {
    cnt++;
    a.order = cnt;
    a.txt = text;
    return a;
  }
};
int MessageFactory::cnt = 0;
// ==================================================
class Recipient {
private:
  vector<Message> messages_;
  void fix_order() { sort(messages_.begin(), messages_.end()); }

public:
  Recipient() {}
  void receive(const Message &msg) { messages_.push_back(msg); }
  void print_messages() {
    fix_order();
    for (auto &msg : messages_) {
      cout << msg.get_text() << endl;
    }
    messages_.clear();
  }
};

// ==================================================
class Network {
public:
  static void send_messages(vector<Message> messages, Recipient &recipient) {
    // simulates the unpredictable network, where sent messages might arrive in
    // unspecified order
    random_shuffle(messages.begin(), messages.end());
    for (auto msg : messages) {
      recipient.receive(msg);
    }
  }
};

int main() {
  MessageFactory message_factory;
  Recipient recipient;
  vector<Message> messages;
  string text;
  while (getline(cin, text)) {
    messages.push_back(message_factory.create_message(text));
  }
  Network::send_messages(messages, recipient);
  recipient.print_messages();
}
