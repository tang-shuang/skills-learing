#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

void print(const boost::system::error_code& /*e*/) {
    std::cout << "定时器触发!" << std::endl;
}

int main() {
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(3));
    
    timer.async_wait(&print);
    
    std::cout << "开始异步等待..." << std::endl;
    io.run(); 
    
    return 0;
}
