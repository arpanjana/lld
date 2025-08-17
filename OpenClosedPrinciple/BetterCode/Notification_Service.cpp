#include <iostream>
#include <vector>
#include <memory>  // for unique_ptr
using namespace std;

class Notification {
public:
    virtual void sendNotification() = 0;
    virtual ~Notification() = default;  // Virtual destructor for proper cleanup
};

class SMS : public Notification {
public:
    void sendNotification() override {
        cout << "Sending the notification through SMS." << endl;
    }
};

class EMAIL : public Notification {
public:
    void sendNotification() override {
        cout << "Sending the notification through Email." << endl;
    }
};

class WHATSAPP : public Notification {
public:
    void sendNotification() override {
        cout << "Sending the notification through WhatsApp." << endl;
    }
};

class NotificationService {
public:
    void send(const vector<unique_ptr<Notification>>& collection) {
        for (const auto& it : collection) {
            it->sendNotification();
        }
    }
};

int main() {
    NotificationService service;

    // Use unique_ptr in vector to manage ownership automatically
    vector<unique_ptr<Notification>> notificationType;
    notificationType.push_back(make_unique<SMS>());
    notificationType.push_back(make_unique<EMAIL>());
    notificationType.push_back(make_unique<WHATSAPP>());

    service.send(notificationType);

    // No need to manually delete - unique_ptr handles it
    return 0;
}
