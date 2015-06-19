#include "chatmessage.pb.h"
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(void) {
    int sockfd = 0;
    int n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr;

    memset(recvBuff, '0', sizeof(recvBuff));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "Could not create socket." << std::endl;
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9000);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "Connection failed." << std::endl;
        return 1;
    }
    while (1) {
        while ((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0) {
            recvBuff[n] = 0;
            if (fputs(recvBuff,stdout) == EOF) {
                std::cout << "Fputs error." << std::endl;
            }
            std::cout << std::endl;
        }
    }
    if (n < 0) {
        std::cout << "Read error." << std::endl;
    }
    return 0;
}
