#include<iostream>
#include<string>

using namespace std;

// Subject
class ChatRoom {
    public:
    virtual void sendMessage(string message, string username) = 0;
};

// RealSubject
class PrivateChatRoom : public ChatRoom {
    public:
    void sendMessage(string message, string username) override {
        cout << "PrivateChatRoom: " << username << " " << message << endl;
    }
};

// Proxy
class ProxyChatRoom : public ChatRoom {
    private:
    ChatRoom* chatroom;
    
    public:
    ProxyChatRoom(ChatRoom* chatroom) { this->chatroom = chatroom; }
    
    void sendMessage(string message, string username) override {
        if (username == "admin") {
            chatroom->sendMessage(message, username);
        } else {
            cout << "Denied: You are not admin\n";
        }
    }
};

int main(int argc, char* argv[]) {
    ChatRoom* chatroom = new ProxyChatRoom(new PrivateChatRoom());
    chatroom->sendMessage("Hello", "admin");
    chatroom->sendMessage("Hello", "user");
    
    delete chatroom;
    return 0;
}

/* Output: */
/*
PrivateChatRoom: admin Hello
Denied: You are not admin
*/