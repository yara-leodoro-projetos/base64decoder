#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <opencv4/opencv2/opencv.hpp>
#include <chrono>
#include "base64CPPREST.hpp"

using namespace std;
using namespace std::chrono;
using namespace utility::conversions;


typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

void printExecutionTime(ClockTime start_time, ClockTime end_time)
{
    auto execution_time_ns = duration_cast<nanoseconds>(end_time - start_time).count();
    auto execution_time_ms = duration_cast<microseconds>(end_time - start_time).count();
    auto execution_time_mss = duration_cast<milliseconds>(end_time - start_time).count();
    auto execution_time_sec = duration_cast<seconds>(end_time - start_time).count();
    auto execution_time_min = duration_cast<minutes>(end_time - start_time).count();
    auto execution_time_hour = duration_cast<hours>(end_time - start_time).count();

    cout << "\nExecution Time: ";
    if (execution_time_hour > 0)
        cout << "" << execution_time_hour << " Hours, ";
    if (execution_time_min > 0)
        cout << "" << execution_time_min % 60 << " Minutes, ";
    if (execution_time_sec > 0)
        cout << "" << execution_time_sec % 60 << " Seconds, ";
    if (execution_time_mss > 0)
        cout << "" << execution_time_mss % 1000 << " Milliseconds, ";
    if (execution_time_ms > 0)
        cout << "" << execution_time_ms % long(1E+3) << " MicroSeconds, ";
    if (execution_time_ns > 0)
        cout << "" << execution_time_ns % long(1E+6) << " NanoSeconds, ";
    cout << endl;
}

// int main(int, char **)
// {
//     std::ifstream file("/home/bruno/b64-cpp/b64_img");
//     std::string b64;
//     std::getline(file, b64);
//     // Base64 decoder;

//     ClockTime start = Clock::now();
//     for (size_t i = 0; i < 1000; i++)
//     {
//         cv::Mat img;
//         auto decoded = decoder.decode(b64);
//         img = cv::imdecode(decoded, cv::IMREAD_COLOR); /* code */
//     }
//     ClockTime end = Clock::now();
//     printExecutionTime(start, end);
// }

int main(int argc, char const *argv[])
{
    std::string encoded_string;

    std::ifstream ofs("/home/iara/C++/Imagebase64/b64");
    std::getline(ofs, encoded_string);
    ofs.close();


    ClockTime start = Clock::now();
    for (size_t i = 0; i < 1000; i++)
    {
        auto image = utility::conversions::from_base64(encoded_string);

        cv::Mat imagew = cv::imdecode(image, cv::IMREAD_COLOR);
    }
    ClockTime end = Clock::now();
    printExecutionTime(start, end);

    return 0;
}
