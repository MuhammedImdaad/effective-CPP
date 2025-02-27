#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std::literals;

using Time = steady_clock::time_point;
enum class Sound
{
    Beep,
    Siren,
    Whistle
};
using Duration = steady_clock::duration;

void setAlarm(Time t, Sound s, Duration d)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
};

int main()
{
    /* we’ll want an alarm that will go off an hour after it’s set and
    that will stay on for 30 seconds. The alarm sound, however, remains undecided.
    We can write a lambda that revises setAlarm’s interface
    so that only a sound needs to be specified:*/

    setAlarm(steady_clock::now() + hours(1), Sound::Siren, seconds(30)); // 1 hour from now

    auto lambda = [](Sound s)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        using namespace std::chrono;
        setAlarm(steady_clock::now() + 1h, s, 30s);
    };

    // do something, time passes

    lambda(Sound::Whistle); // 1 hour from now

    // do something, time passes

    lambda(Sound::Beep); // 1 hour from now
    return 0;
}