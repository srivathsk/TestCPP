#include<boost/thread.hpp>
#include<iostream>
#include<boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost;

class Timer 
{
    public:
        Timer(int secs)
            : interval(1)
        {}

        void start()
        {
            //m_pthread = new boost::thread(&Timer::tick, this, boost::asio::placeholders::error);
            m_pthread = new boost::thread(&Timer::threadFn, this);
        }

        void threadFn()
        {
            cout << "Thread started" << endl;
            boost::asio::io_service io;
            int count = 0;
            boost::asio::deadline_timer t(io, interval);
            t.async_wait(boost::bind(&Timer::tick, this, boost::asio::placeholders::error, &t, &count));
            io.run();
        }

        void join()
        {
            m_pthread->join();
        }

	void tick(const boost::system::error_code& /*e*/, boost::asio::deadline_timer* t, int* count) {
	//void tick() {
	
	        std::cout << "tick" << std::endl;
	
	        // Reschedule the timer for 1 second in the future:
	        t->expires_at(t->expires_at() + interval);
	        // Posts the timer event
	        t->async_wait(boost::bind(&Timer::tick, this, boost::asio::placeholders::error, t, count));
	}

    private:
        boost::thread* m_pthread;
        boost::posix_time::seconds interval; 
};

void testFn()
{
    cout << "Thread started" << endl;
}

int main()
{
    //boost::thread t1(testFn);
    cout << "Processing Timer thread " << endl;
    Timer prog_timer(2);
    prog_timer.start();
    prog_timer.join();
    //t1.join();
    //
    // start a timer
}
