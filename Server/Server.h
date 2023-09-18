#include <iostream>
#include <string>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using boost::asio::ip::tcp;
using std::string;
using std::cout;
using std::endl;

class Session : public std::enable_shared_from_this<Session> {
    public:
        Session(tcp::socket socket) : socket_(std::move(socket)) {}

        void start() {
            doRead();
        }

private:
    void doRead() {
        auto self(shared_from_this());
        boost::asio::async_read_until(socket_, buf_, "\n", [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                std::istream response_stream(&buf_);
                std::string reply;
                std::getline(response_stream, reply);
                cout << "Readed from Client: " << reply << endl; 
                buf_.consume(length);
                doRead();
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
                    cout<<"Socket Connected";
                }
                doAccept();
            });
        }

    
private:
    tcp::acceptor acceptor_;
};
