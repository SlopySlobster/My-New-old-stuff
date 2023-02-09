#include <iostream>
#include<SFML/Network.hpp>

int main()
{
    std::cout << "Client[c] or server[s]? " << std::endl;
    std::string consoleInput;
    std::getline(std::cin, consoleInput);
    if (consoleInput == "c")
    {
        std::cout << "Input server address: " << std::endl;
        std::getline(std::cin, consoleInput);

        // ----- The client -----
        // Create a socket and connect it to port 55001
        sf::TcpSocket socket;
        socket.connect(consoleInput, 55001);

        // Send a message to the connected host
        std::string message = "MUngus";
        socket.send(message.c_str(), message.size() + 1);

        // Receive an answer from the server
        char buffer[1024];
        std::size_t received = 0;
        socket.receive(buffer, sizeof(buffer), received);
        std::cout << "The server said: " << buffer << std::endl;
        std::cout << "Press any key to close" << std::endl;
        std::cin >> message;
    }
    else if (consoleInput == "s")
    {
        // ----- The server -----
        // Create a listener to wait for incoming connections on port 55001
        sf::TcpListener listener;
        listener.listen(55001);

        //Show ip address
        std::cout << sf::IpAddress::getLocalAddress() << std::endl;
        std::cout << sf::IpAddress::getPublicAddress() << std::endl;

        // Wait for a connection
        sf::TcpSocket socket;
        listener.accept(socket);
        std::cout << "New client connected: " << socket.getRemoteAddress() << std::endl;

        // Receive a message from the client
        char buffer[1024];
        std::size_t received = 0;
        socket.receive(buffer, sizeof(buffer), received);
        std::cout << "The client said: " << buffer << std::endl;

        // Send an answer
        std::string message = "You are very sus";
        socket.send(message.c_str(), message.size() + 1);

        std::cout << "Press any key to close" << std::endl;
        std::cin >> message;
    }

    return 0;
}
