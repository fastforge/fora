#include<boost/asio.hpp>


int main(int argc, char *argv[])
{
    using namespace boost::asio;
    io_service service;
    ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 2001);
    ip::tcp::socket sock(service);
    boost::system::error_code ec;
    sock.connect(ep, ec);
    sock.write_some(buffer("GET /index.html\r\n"));
    char buff[1204] = { 0 };
    sock.read_some(buffer(buff, 1204));
    printf("received: %s\n", buff);
    sock.shutdown(ip::tcp::socket::shutdown_receive);
    sock.close();
}
