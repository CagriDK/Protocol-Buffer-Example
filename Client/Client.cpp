#include "Client.h"

int main(int, char**){
    cout << "Client is starting...\n";
    boost::asio::io_context io_context;
    TCPClient client(io_context, "127.0.0.1", "55000");  // IP ve portu ayarlayın
    // Send and receive fonksiyonunu ayrı bir thread'de çalıştır
    std::thread sendReceiveThread([&client]() {
        client.sendAndReceive();
    });

    io_context.run();
    // Eğer io_context.run() durursa, sendReceiveThread'in de durmasını sağla
    sendReceiveThread.join();

}
