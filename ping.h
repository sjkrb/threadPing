#ifndef PING_H
#define PING_H
#include <atomic>
#include <cstdlib>
#include <format>
#include <future>
#include <string_view>
#include <thread>

class Pinger
{
public:
    Pinger(std::string_view ip)
    {
        T = std::thread(&Pinger::doPing, this, ip);
        T.detach();
    }

    ~Pinger()
    {
        std::terminate();
    }

    std::atomic_bool is_on()
    {
        return !m_is_on.load();
    }

private:
    std::atomic_bool m_is_on{std::false_type()};
    std::thread T;

    //func
    void doPing(std::string_view ip)
    {
        while (true) {
            m_is_on.store(static_cast<bool>(system(std::format("ping -c1 -s1 {}  > /dev/null 2>&1", ip).c_str())));
        }
    }
};

#endif // PING_H
