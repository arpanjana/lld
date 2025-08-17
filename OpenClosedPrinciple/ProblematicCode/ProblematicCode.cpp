#include <iostream>
#include <vector>
using namespace std;

enum class NotificationType
{
    SMS,
    WHATSAPP,
    EMAIL
};

void sendSMSNotification()
{
    cout<<"Sending the notification through SMS."<<endl;
}

void sendWhatsappNotification()
{
    cout<<"Sending the notification through whatsapp."<<endl;
}

void sendEmailNotification()
{
    cout<<"Sending the notification through Email."<<endl;
}

class NotificationService
{
    public:
        void sendNotification(vector<NotificationType>& collection)
        {
            for(auto it:collection )
            {
                if(it == NotificationType::SMS){
                    sendSMSNotification();
                }
                else if(it == NotificationType::EMAIL)
                {
                    sendEmailNotification();
                }
                else if(it == NotificationType::WHATSAPP)
                {
                    sendWhatsappNotification();
                }
            }   
        }
};

int main() {
    NotificationService service;
    vector<NotificationType> notificationType;
    notificationType.push_back(NotificationType::SMS);
    notificationType.push_back(NotificationType::EMAIL);
    notificationType.push_back(NotificationType::WHATSAPP);
    service.sendNotification(notificationType);
}
