#include <iostream>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::tcp;
using std::string;
using namespace std;

class TCPClient {
public:
    TCPClient(boost::asio::io_context& io_context, const string& host, const string& port)
        : socket_(io_context), resolver_(io_context) {
        doResolve(host, port);
    }

    void sendAndReceive() {
        for (;;) {
            
            cout << "Enter message and send to server (or 'exit' to quit): ";
            getline(std::cin, input_message_);

            if (input_message_ == "exit") break;

            doWrite();
            io_context_.run();
            io_context_.restart();
        }
    }

private:
    void doResolve(const string& host, const string& port) {
        cout<<"doResolve started.\n";
        resolver_.async_resolve(host, port, [this,host,port](boost::system::error_code ec, tcp::resolver::results_type results) {
            if (!ec) {
                cout<<"async_resolve started.\n";
                boost::asio::async_connect(socket_, results, [this,host,port](boost::system::error_code ec, tcp::endpoint) {
                    if (!ec) {
                        cout<<"async_connect Connection Succesfull.\n";
                        // Connection successful start to Reading from server!
                        //doRead();
                    } else{
                        cout << "async_connect failed. Retrying in 5 seconds.\n";
                    // Bağlantı başarısız oldu, 5 saniye bekleyip yeniden deneyin.
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    doResolve(host, port);
                    }
                });
            }
            else {
                cout << "async_connect failed. Retrying in 5 seconds.\n";
                    // Bağlantı başarısız oldu, 5 saniye bekleyip yeniden deneyin.
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    doResolve(host, port);
            }
        });
    }

    void doWrite() {
        boost::asio::async_write(socket_, boost::asio::buffer(input_message_ + "\n"), 
            [this](boost::system::error_code ec, std::size_t) {
                if (!ec) {
                    // ;
                }
            }
        );
    }

    void doRead() {
        boost::asio::async_read_until(socket_, response_, "\n",
            [this](boost::system::error_code ec, std::size_t) {
                if (!ec) {
                    std::istream response_stream(&response_);
                    std::string reply;
                    std::getline(response_stream, reply);
                    cout << "Reply from server: " << reply << endl;
                    doRead();
                }
            }
        );
    }

    boost::asio::io_context io_context_;
    tcp::socket socket_;
    tcp::resolver resolver_;
    boost::asio::streambuf response_;
    string input_message_;
};