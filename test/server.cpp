#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <sys/select.h>

using namespace std;

#define PORT 8080


#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024


int main() {
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(clientAddr);
    
    // 创建套接字
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        cerr << "Error creating socket" << endl;
        return 1;
    }

    // 设置服务器地址结构
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);          // 设置端口号
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // 绑定套接字
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "Error binding socket" << endl;
        close(serverSocket);
        return 1;
    }

    // 监听连接
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        cerr << "Error listening" << endl;
        close(serverSocket);
        return 1;
    }
    cout << "Server listening on port 8080:" << endl;


    // 初始化客户端套接字向量
    vector<int> client_sockets;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = 0;
    }

    fd_set readfds;             // 文件描述符集
    int max_sd, activity, new_socket;
    while (1)
    {
        // 清空文件描述符集
        FD_ZERO(&readfds);

        // 将服务器套接字添加到文件描述符集
        FD_SET(serverSocket, &readfds);
        max_sd = serverSocket;              // 设置最大文件描述符

        // 将客户端套接字添加到文件描述符集
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_sockets[i];
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }
            if (sd > max_sd) {
                max_sd = sd;
            }
        }
    }
    





    // 接收连接
    int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrSize);
    if (clientSocket < 0) {
        cerr << "Error accepting connection" << endl;
        close(serverSocket);
        return 1;
    }

    cout << "Client connected" << endl;

    // 接收数据
    char buffer[BUFFER_SIZE];
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead < 0) {
        cerr << "Error reading from socket" << endl;
    } else {
        buffer[bytesRead] = '\0'; // 确保字符串以null结尾
        cout << "Received message: " << buffer << endl;
    }

    // 关闭套接字
    close(clientSocket);
    close(serverSocket);

    return 0;
}