#include<iostream>
#include<boost/thread.hpp>
#include<boost/thread/mutex.hpp>
#include<fstream>

using namespace std;

boost::mutex fn_mutex;

class ThreadSafeLog {
    public: 
        ThreadSafeLog(const string& logFile)
        {
            m_ofp.open(logFile, ios::w);
        }

        void writeString(const string& msg)
        {
            boost::unique_lock<boost::mutex> scoped_lock(m_mutex);
            m_ofp << msg << endl;
        }

    private:
        std::ofstream m_ofp;
        boost::mutex m_mutex;
};

void fn(const string& msg, std::ofstream& ofp)
{
    for (size_t i=100; i>0; --i)
    {
        boost::unique_lock<boost::mutex> scoped_lock(fn_mutex);
        ofp << msg << i << endl;
    }
}

int main()
{
    std::ofstream ofp;
    ofp.open("LogThread.txt", ios::w);
    boost::thread* fnThread = new boost::thread(fn, "Thread_function : ", ofp);
    fn("Main_Function : ", ofp);
    /*for (size_t i=100; i>0; --i)
    {
        cout << "Main_function : " << i << endl;
    }*/
    //fnThread->join();
}
