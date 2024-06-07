#include <iostream>
#include <stdexcept>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

class Socket {
public:
    Socket(int domain, int type, int protocol) {
        sockfd = socket(domain, type, protocol);
        if (sockfd == -1) {
            throw std::runtime_error("Failed to create socket: " + std::string(strerror(errno)));
        }
        
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

    Socket(Socket&& other): sockfd(other.sockfd) {
        other.sockfd = -1;
    }

    Socket& operator=(Socket&& other) {
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