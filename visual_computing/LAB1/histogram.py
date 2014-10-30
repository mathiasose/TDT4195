#! /usr/bin/python

from __future__ import print_function, division
from collections import defaultdict
import os

import numpy as np
import matplotlib.pyplot as pl
import matplotlib.cm as cm
from scipy.misc.pilutil import imsave, imread

from gamma import pixel_wise_transform


OUTPUT_DIR = 'output/'


def random_matrix(w, h, n):
    '''
    :returns a w*h matrix with random integers in the range [0, n>
    '''
    return np.random.randint(n, size=(h, w))


def create_histogram(matrix):
    histogram = defaultdict(int)
    for row in matrix:
        for px in row:
            histogram[px] += 1

    return histogram


def normalize_histogram(histogram):
    normalized = dict()
    total = sum(histogram.values())
    for key, value in histogram.iteritems():
        normalized[key] = value / total

    return normalized


def create_cdf(normalized_histogram):
    '''
    :returns a cummulative distribution function that can be called with a value parameter
    '''
    return lambda i: sum(normalized_histogram[j] for j in [v for v in normalized_histogram.keys() if v <= i])


def main():
    matrix = random_matrix(4, 4, n=8)

    output_path = os.path.join(OUTPUT_DIR, 'original_matrix.png')
    imsave(output_path, matrix)

    histogram = create_histogram(matrix)
    normalized = normalize_histogram(histogram)
    cdf = create_cdf(normalized)
    image = pixel_wise_transform(matrix, cdf)

    print(matrix)
    print(image)

    output_path = os.path.join(OUTPUT_DIR, 'normalized_matrix.png')
    imsave(output_path, image)
    pl.imshow(image, cmap=cm.Greys_r)
    pl.show()

    EINSTEIN = 'img/einstein_lowcontrast.png'
    einstein = imread(EINSTEIN)
    ein_cdf = create_cdf(normalize_histogram(create_histogram(einstein)))
    imsave(os.path.join(OUTPUT_DIR, "cdf_" + os.path.split(EINSTEIN)[-1]), pixel_wise_transform(einstein, ein_cdf))


if __name__ == "__main__":
    main()