#pragma once

#include <vector>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

class MeanShift {
public:
	static std::vector<float> cluster(const std::vector<float>& original_X, float kernel_bandwidth, float distance, int n_iterations = 5, float look_distance = 0.1);
	static float angular_distance(float x, float xi);
	static float regularize_angle(float x);
	static std::vector<float> neighbourhood_points(std::vector<float>& X, float x_centroid, float distance = 5);
	static float gaussian_kernel(float distance, float bandwidth);
};

