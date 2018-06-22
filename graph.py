import matplotlib.pyplot as plt
import numpy as np
import argparse

def main(filename):
	data = [float(x) for x in open(filename, 'r').readlines()]
	angles = list(range(len(data)))
	
	plt.plot(angles, data)

	plt.xlabel('Angle')
	plt.ylabel('votes')
	plt.title('Votes in the Hough space')
	plt.grid(True)
	plt.savefig("result.png")
	plt.show()

if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("filename", help="path to file")
	args = parser.parse_args()
	
	main(args.filename)