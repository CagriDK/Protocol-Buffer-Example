#include <iostream>
#include <string>
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
class Client{
public:
    Client(int port,std::string IpAddr);

private:
    int m_port;
    std::string IpAddr;
};