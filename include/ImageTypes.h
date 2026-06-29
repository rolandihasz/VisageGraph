#pragma once
#include <vector>
#include <cstdint>
#include <string>

// Contiguous buffer for raw pixel data decoded from disk
struct ImageBuffer {
    std::vector<uint8_t> pixels;
    int width{0};
    int height{0};
    int channels{0}; // 1 for Grayscale (Detection), 3 for RGB
};

// Represents an isolated face within the image
struct FaceROI {
    int x{0}, y{0}, width{0}, height{0};
    std::vector<float> embedding; // The 128-dimensional output from our math engine
};

// The metadata payload we will eventually ship to Cloudflare Vectorize
struct ImageMetadata {
    std::string filePath;
    std::vector<FaceROI> detectedFaces;
};