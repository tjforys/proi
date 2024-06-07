#include "socket.hpp"

int main() {
    try {
        Socket server_socket(AF_INET, SOCK_STREAM, 0);
        
        sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(8888);

        server_socket.bind(reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr));
        server_socket.listen(10);

        std::cout << "Server is listening on port 8888..." << std::endl;

        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = server_socket.accept(reinterpret_cast<sockaddr*>(&client_addr), &client_len);

        std::cout << "Accepted a connection from " << inet_ntoa(client_addr.sin_addr) << std::endl;

        close(client_socket);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}