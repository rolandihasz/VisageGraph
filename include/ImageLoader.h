#pragma once
#include "ImageTypes.h"
#include <string>
#include <iostream>

// This macro tells stb_image to create the actual implementation here.
// It should only be defined in exactly ONE .cpp file in your whole project,
// but for a quick start, we can inline it if you only include this header once.
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class ImageLoader {
public:
    // We force Grayscale (1 channel) because HOG gradient math doesn't need color,
    // and it cuts our memory footprint by 66% instantly.
    static bool LoadToGrayscale(const std::string& path, ImageBuffer& outBuffer) {
        int w, h, channels;
        
        unsigned char* data = stbi_load(path.c_str(), &w, &h, &channels, 1);
        
        if (!data) {
            std::cerr << "[I/O Error] Failed to decode: " << path << "\n";
            return false;
        }

        outBuffer.width = w;
        outBuffer.height = h;
        outBuffer.channels = 1;
        
        // Fast block copy into our contiguous vector
        size_t byteCount = w * h;
        outBuffer.pixels.assign(data, data + byteCount);

        stbi_image_free(data);
        return true;
    }
};