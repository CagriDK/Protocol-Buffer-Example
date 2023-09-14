#include "Server.h"
#include <thread>

int main(int, char**){
    try{
        cout<<"Server is starting...\n";
        boost::asio::io_context io_context;
        Server server(io_context,55000);
        io_context.run();

    }
    catch(std::exception& all)
    {
        cout<<"The Catch = "<<all.what()<<"\n";
    }
}
