#include <cpprest/details/web_utilities.h>
#include <iostream>
#include <vector>
#include <opencv4/opencv2/opencv.hpp>
#include "base64CPPREST.hpp"

using namespace utility::conversions;

void base64()
{
    std::string encoded_string;

    std::ifstream ofs("/home/iara/C++/Imagebase64/b64");
    std::getline(ofs, encoded_string);
    ofs.close();

   auto image = utility::conversions::from_base64(encoded_string);

   cv::Mat imagew = cv::imdecode(image, cv::IMREAD_COLOR);

    //    cv::imshow("Image", imagew);
    //    cv::waitKey(0);
}

