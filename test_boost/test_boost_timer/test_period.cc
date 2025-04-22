#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

class periodic_timer {
public:
    periodic_timer(boost::asio::io_service& io, int interval)
        : timer_(io, boost::posix_time::seconds(interval)), count_(0) {
        timer_.async_wait(boost::bind(&periodic_timer::on_timer, this, _1));
    }
    
    void on_timer(const boost::system::error_code& e) {
        if (e) {
            std::cerr << "定时器错误: " << e.message() << std::endl;
            return;
        }
        
        std::cout << "定时器触发 #" << ++count_ << std::endl;
        
        timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
        timer_.async_wait(boost::bind(&periodic_timer::on_timer, this, _1));
    }
    
private:
    boost::asio::deadline_timer timer_;
    int count_;
};

int main() {
    boost::asio::io_service io;
    periodic_timer t(io, 1);
    
    io.run();
    return 0;
}
