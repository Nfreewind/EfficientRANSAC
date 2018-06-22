#include "MeanShift.h"

std::vector<float> MeanShift::cluster(const std::vector<float>& original_X, float kernel_bandwidth, float distance, int n_iterations, float look_distance) {
	std::vector<float> X = original_X;

	//std::vector<float> past_X;
	for (int iter = 0; iter < n_iterations; iter++) {
		for (auto& x : X) {
			// Step 1. For each datapoint x \in X, find the neighbouring points N(x) of x.
			std::vector<float> neighbours = neighbourhood_points(X, x, look_distance);

			// Step 2. For each datapoint x \in X, calculate the mean shift m(x).
			float numerator = 0;
			float denominator = 0;
			for (auto neighbour : neighbours) {
				// normalize neighbour to [0, PI/2]
				neighbour = regularize_angle(neighbour);
				if (neighbour > CV_PI * 0.5) neighbour -= CV_PI * 0.5;

				if (neighbour - x > CV_PI * 0.25) neighbour -= CV_PI * 0.5;
				else if (x - neighbour > CV_PI * 0.25) neighbour += CV_PI * 0.5;

				distance = angular_distance(neighbour, x);
				if (distance > CV_PI * 0.25) distance = CV_PI * 0.5 - distance;

				float weight = gaussian_kernel(distance, kernel_bandwidth);
				numerator += (weight * neighbour);
				denominator += weight;
			}

			float new_x = numerator / denominator;

			// Step 3. For each datapoint x \in X, update x <- m(x).
			x = new_x;
		}

		//past_X.append(np.copy(X))
	}

	return X;
}

/**
 * return angle difference [0, PI/2]
 */
float MeanShift::angular_distance(float x, float xi) {
	x = regularize_angle(x);
	xi = regularize_angle(xi);

	if (std::abs(x - xi) <= CV_PI * 0.5) return std::abs(x - xi);
	else return CV_PI - std::abs(x - xi);
}

/**
 * return angle [0, PI]
 */
float MeanShift::regularize_angle(float x) {
	if (x < 0) {
		x += CV_PI * (int)(-x / CV_PI + 1);
	}
	else {
		x -= CV_PI * (int)(x / CV_PI);
	}

	//if (x > CV_PI * 0.5) x -= CV_PI * 0.5;

	return x;
}

std::vector<float> MeanShift::neighbourhood_points(std::vector<float>& X, float x_centroid, float distance) {
	std::vector<float> eligible_X;

	for (auto& x : X) {
		float distance_between = angular_distance(x, x_centroid);

		// print('Evaluating: [%s vs %s] yield dist=%.2f' % (x, x_centroid, distance_between))
		if (distance_between <= distance) {
			eligible_X.push_back(x);
		}
	}

	return eligible_X;
}

float MeanShift::gaussian_kernel(float distance, float bandwidth) {
	float val = (1 / (bandwidth * std::sqrt(2 * CV_PI))) * std::exp(-0.5 * std::pow(distance / bandwidth, 2));
	return val;
}