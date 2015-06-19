#include "network.h"
#include <iostream>

int main() {
    network client("localhost","9000",false);
    client.sendMsg("hello");
}
