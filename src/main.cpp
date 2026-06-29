#include <iostream>
#include "ImageTypes.h"
#include "ImageLoader.h"

int main() {
    std::cout << "Booting Vision Engine...\n";
    
    ImageBuffer myImage;
    std::string testPath = "sample_test_photo.jpg"; // Point this to a real file
    
    if (ImageLoader::LoadToGrayscale(testPath, myImage)) {
        std::cout << "Success! Loaded " << testPath << "\n";
        std::cout << "Resolution: " << myImage.width << "x" << myImage.height << "\n";
        std::cout << "Total Pixels in RAM: " << myImage.pixels.size() << " bytes\n";
    }

    return 0;
}