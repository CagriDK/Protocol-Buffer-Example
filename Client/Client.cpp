#include "Client.h"

int main(int, char**){
    com::example::Client msg;
    msg.set_id("1234");
    msg.set_name("Cagri");
    msg.set_account_balance(10000);
    msg.set_email("cagridknl@gmail.com");
    std::string dataSender = msg.SerializeAsString();

    cout << "Client is starting...\n";
    boost::asio::io_context io_context;
    TCPClient client(io_context, "127.0.0.1", "55000");  // IP ve portu ayarlayın
    client.setMessage(dataSender);
    // Send and receive fonksiyonunu ayrı bir thread'de çalıştır
    std::thread sendReceiveThread([&client]() {
        client.sendAndReceive();
    });

    io_context.run();
    // Eğer io_context.run() durursa, sendReceiveThread'in de durmasını sağla
    sendReceiveThread.join();

}
