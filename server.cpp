#include "network.h"
#include "chatmessage.pb.h"
#include <iostream>
#include <string>

int main() {
    network server("localhost","9000",true);
    while (true) {
        std::string buffer;
        chatroom::ChatMessage mess;
        server.recieveMsg(buffer);
        mess.ParseFromString(buffer);
        std::cout << mess.name() << std::endl;
        std::cout << mess.text() << std::endl;
    }
}
