#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::cout << "Enter the time in the format mm (minutes) ss (seconds)" << std::endl;
    int minutes, seconds;
    std::cin>>minutes>>seconds;

    int time = minutes * 60 + seconds;
    std::time_t time_now = std::time(nullptr);
    std::time_t finish_time=time_now+time;

    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);

    while (std::time(nullptr)<finish_time) {
        std::time_t currentTime = std::time(nullptr);
        std::time_t remainingTime = finish_time - currentTime;

        int remainingMinutes = remainingTime / 60;
        int remainingSeconds = remainingTime % 60;

        local.tm_min=remainingMinutes;
        local.tm_sec=remainingSeconds;
        std::cout << std::put_time(&local,"%M:%S") << std::endl;

        while (std::time(nullptr) == currentTime) { }
    }
    std::cout << "DING! DING! DING!" << std::endl;
}
