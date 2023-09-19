#include <iostream>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include "ProtoFiles/ServerData.pb.h"

using boost::asio::ip::tcp;
using boost::asio::ip::tcp;
using std::string;
using std::cout;
using std::endl;

class Session : public std::enable_shared_from_this<Session> {
    public:
        Session(tcp::socket socket) : socket_(std::move(socket)) {}

        void start() {
            doReadHeader();
        }

private:
void doReadHeader() {
    auto self(shared_from_this());
    
    buf_.prepare(sizeof(uint32_t));
    
    boost::asio::async_read(socket_, buf_, boost::asio::transfer_exactly(sizeof(uint32_t)), 
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::istream is(&buf_);
                uint32_t messageSize;
                is.read(reinterpret_cast<char*>(&messageSize), sizeof(uint32_t));
                messageSize = ntohl(messageSize);
                
                buf_.consume(sizeof(uint32_t));  // Tüketiyoruz!
                
                doReadBody(messageSize);
            } else {
                std::cout << "Message error = " << ec.message() << std::endl;
            }
        });
}

void doReadBody(std::size_t messageSize) {
    auto self(shared_from_this());
    
    buf_.prepare(messageSize);
    
    boost::asio::async_read(socket_, buf_, boost::asio::transfer_exactly(messageSize),
        [this,messageSize, self](boost::system::error_code ec, std::size_t) {
            if (!ec) {
                std::istream is(&buf_);
                std::vector<char> body(messageSize);
                is.read(body.data(), messageSize);
                
                buf_.consume(messageSize);  // Tüketiyoruz!
                
                msg.ParseFromArray(body.data(), body.size());
                std::cout<<"== Proto message datas ==\n";
                std::cout << "id              = " << msg.id() << "\n";
                std::cout << "name            = " << msg.name() << "\n";
                std::cout << "account_balance = " << msg.account_balance() << "\n";
                std::cout << "email           = " << msg.email() << "\n";
                std::cout << std::endl;
                doReadHeader();
            } else {
                std::cout << "Message error = " << ec.message() << std::endl;
            }
        });
}







    // void doWrite(std::size_t length) {
    //     auto self(shared_from_this());
    //     // Write the exact message received back to the client
    //     boost::asio::async_write(socket_, buf_.data(), 
    //     [this,length, self](boost::system::error_code ec, std::size_t) {
    //         if (!ec) {
    //             buf_.consume(length); // Remove the written data
    //         }
    //     });
    // }

    tcp::socket socket_;
    boost::asio::streambuf buf_;
    com::example::Client msg;
    };
class Server{
public:
    Server(boost::asio::io_context& io_context, unsigned short port)
     :  acceptor_(io_context,tcp::endpoint(tcp::v4(),port)){
        doAccept();
     }
private:
    void doAccept() {
            acceptor_.async_accept([this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket))->start();
                    cout<<"Socket Connected \n";
                }
                doAccept();
            });
        }

    
private:
    tcp::acceptor acceptor_;
};
