#include <iostream>
#include <vector>
#include <ostream>
#include <string.h>
#include <fstream>
#include <Poco/Base64Decoder.h>
#include <opencv4/opencv2/opencv.hpp>


std::string decode64(std::string stringbase64)
{
    std::stringstream base64;
    base64 << stringbase64;
    Poco::Base64Decoder decoder(base64);

    std::vector<u_char> buffer;

    cv::Mat image = cv::imdecode(buffer, cv::IMREAD_COLOR);

    cv::imshow("Imagebase64", image);
    cv::waitKey(0);    
}
