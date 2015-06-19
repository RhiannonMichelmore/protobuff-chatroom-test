#include "network.h"
#include <iostream>
#include <string>

int main() {
    network server("localhost","9000",true);
    while (true) {
        std::string buffer;
        server.recieveMsg(buffer);
        std::cout << buffer << std::endl;
    }
}
