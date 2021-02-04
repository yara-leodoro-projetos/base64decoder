#include <iostream>
#include <vector>
#include <ostream>
#include <string.h>
#include <fstream>
#include <Poco/StreamCopier.h>
#include <Poco/Base64Decoder.h>
#include <Poco/Buffer.h>
#include <Poco/AutoPtr.h>
#include <opencv4/opencv2/opencv.hpp>
#include <memory>
#include <b64/decode.h>


void decode64()
{
    std::string encoded_string;
    std::ifstream ofs("/home/iara/C++/Imagebase64/b64");
    std::getline(ofs, encoded_string);
    ofs.close();

    std::stringstream ss;
    std::stringstream a;
    ss << encoded_string;
    
    Poco::Base64Decoder decoder(ss);
    decoder.seekg(0, decoder.end);
    int leg = decoder.tellg();
    decoder.seekg(0, decoder.beg);



    // cv::Mat image = cv::imdecode(cv::Mat(data), cv::IMREAD_COLOR);
    // cv::imshow("Imagebase64", image);
    // cv::waitKey(0);    
}

int main(int argc, char const *argv[])
{
    decode64();
    return 0;
}
