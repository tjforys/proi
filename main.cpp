#include <iostream>
#include <stdexcept>
#include <cstring>      // For memset
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Socket {
public:
    Socket(int domain, int type, int protocol) {
        sockfd = ::socket(domain, type, protocol);
        if (sockfd == -1) {
            throw std::runtime_error("Failed to create socket: " + std::string(strerror(errno)));
        }
        // Set SO_REUSEADDR option
        int opt = 1;
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
            throw std::runtime_error("Failed to set SO_REUSEADDR: " + std::string(strerror(errno)));
        }
    }

    ~Socket() {
        if (sockfd != -1) {
            ::close(sockfd);
        }
    }

    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;

    Socket(Socket&& other) noexcept : sockfd(other.sockfd) {
        other.sockfd = -1;
    }

    Socket& operator=(Socket&& other) noexcept {
        if (this != &other) {
            if (sockfd != -1) {
                ::close(sockfd);
            }
            sockfd = other.sockfd;
            other.sockfd = -1;
        }
        return *this;
    }

    int get() const {
        return sockfd;
    }

    void bind(const struct sockaddr* addr, socklen_t addrlen) {
        if (::bind(sockfd, addr, addrlen) == -1) {
            throw std::runtime_error("Failed to bind socket: " + std::string(strerror(errno)));
        }
    }

    void listen(int backlog) {
        if (::listen(sockfd, backlog) == -1) {
            throw std::runtime_error("Failed to listen on socket: " + std::string(strerror(errno)));
        }
    }

    int accept(struct sockaddr* addr, socklen_t* addrlen) {
        int client_sock = ::accept(sockfd, addr, addrlen);
        if (client_sock == -1) {
            throw std::runtime_error("Failed to accept connection: " + std::string(strerror(errno)));
        }
        return client_sock;
    }

    void connect(const struct sockaddr* addr, socklen_t addrlen) {
        if (::connect(sockfd, addr, addrlen) == -1) {
            throw std::runtime_error("Failed to connect to server: " + std::string(strerror(errno)));
        }
    }

private:
    int sockfd;
};

int main() {
    try {
        Socket server_socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(8888);

        server_socket.bind(reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr));
        server_socket.listen(10);

        std::cout << "Server is listening on port 8888..." << std::endl;

        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = server_socket.accept(reinterpret_cast<struct sockaddr*>(&client_addr), &client_len);

        std::cout << "Accepted a connection from " << inet_ntoa(client_addr.sin_addr) << std::endl;

        ::close(client_socket);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}