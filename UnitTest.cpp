#include "gtest/gtest.h"
#include "socket.hpp"
#include <thread>
#include <atomic>

std::atomic<int> port_base(8888);

int get_next_port() {
    return port_base.fetch_add(1);
}
TEST(test, test){
    EXPECT_EQ(1, 1);
}

TEST(SocketTest, SocketCreation) {
    EXPECT_NO_THROW(Socket(AF_INET, SOCK_STREAM, 0));
}


TEST(SocketTest, SocketCreationFailure) {
    EXPECT_THROW(Socket(AF_INET, SOCK_STREAM, -1), std::runtime_error);
}

TEST(SocketTest, BindSuccess) {
    Socket server_socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    EXPECT_NO_THROW(server_socket.bind(reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)));
}


TEST(SocketTest, ListenSuccess) {
    Socket server_socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    server_socket.bind(reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr));
    EXPECT_NO_THROW(server_socket.listen(10));
}


TEST(SocketTest, AcceptConnection) {
    //creating socket
    Socket server_socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    server_socket.bind(reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr));
    server_socket.listen(10);

    //creating client to connect to socket
    std::thread client_thread([]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Socket client_socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(8888);
        inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

        client_socket.connect(reinterpret_cast<struct sockaddr*>(&client_addr), sizeof(client_addr));
    });

    //accepting connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_socket = server_socket.accept(reinterpret_cast<struct sockaddr*>(&client_addr), &client_len);
    EXPECT_NE(client_socket, -1); 

    //closing socket
    ::close(client_socket);
    client_thread.join();
}