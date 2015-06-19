#include "network.h"
#include "chatmessage.pb.h"
#include <iostream>

int main() {
    network client("localhost","9000",false);
    chatroom::ChatMessage mess;
    mess.set_name("Rhiba");
    mess.set_text("hello this is dog");
    std::string output;
    mess.SerializeToString(&output);
    client.sendMsg(output);
}
