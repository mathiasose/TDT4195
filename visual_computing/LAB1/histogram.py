from __future__ import print_function, division

import os

import numpy as np
import matplotlib.pyplot as pl
import matplotlib.cm as cm
from scipy.misc.pilutil import imsave

from gamma import pixel_wise_transform
from gamma import minmax_2d


OUTPUT_DIR = 'output/'


def random_matrix(w, h, n):
    '''
    :returns a w*h matrix with random integers in the range [0, n>
    '''
    return np.random.randint(n, size=(h, w))


def n_count(matrix, n):
    '''
    :returns the number of occurences of n in the 2d matrix
    '''
    return sum(sum(x == n for x in row) for row in matrix)


def create_histogram(matrix):
    m_min, m_max = minmax_2d(matrix)
    return dict((n, n_count(matrix, n)) for n in range(m_min, m_max + 1))


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
    histogram = create_histogram(matrix)
    normalized = normalize_histogram(histogram)
    cdf = create_cdf(normalized)
    image = pixel_wise_transform(matrix, cdf)

    print(matrix)
    print(histogram)
    print(normalized)
    print(image)

    output_path = os.path.join(OUTPUT_DIR, 'histogram.png')
    imsave(output_path, image)
    pl.imshow(image, cmap=cm.Greys_r)
    pl.show()


if __name__ == "__main__":
    main()