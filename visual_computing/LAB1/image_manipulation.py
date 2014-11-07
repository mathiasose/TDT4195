#! /usr/bin/python

from __future__ import print_function, division
from copy import deepcopy
from collections import defaultdict

import numpy as np


# utility

def transform(matrix, fun):
    """
    applies fun(px) to every px in the 2d matrix
    """
    return np.asarray(map(lambda row: map(lambda px: fun(px), row), matrix))


def minmax_2d(matrix):
    """
    returns the minimum and maximum value of a 2d matrix
    """
    return map(lambda f: f(f(matrix, key=lambda x: f(x))), (min, max))


def random_matrix(w, h, n):
    """
    :returns a w*h matrix with random integers in the range [0, n>
    """
    return np.random.randint(n, size=(h, w))


# task 3

def normalize_intensity(matrix):
    """
    normalizes the intensity values of the input matrix
    from the [0, 255] integer range to the [0, 1] floating point range
    """
    return transform(matrix, lambda px: px / 255)


def correct_with_flatfield(a, b):
    """
    :returns a new matrix with the quotients of each value in the matrices a and b
    """
    corrected = np.copy(a)
    for y, (a_row, b_row) in enumerate(zip(a, b)):
        for x, (a_px, b_px) in enumerate(zip(a_row, b_row)):
            corrected[y][x] = a_px / b_px

    return corrected


# task 4.1

def gamma_correct(matrix, gamma=1.0):
    """
    applies the gamma correction function (px)^(gamma) to the matrix
    """
    return transform(matrix, lambda px: int(255 * ((px / 255) ** gamma)))


def stretch_range(matrix):
    """
    stretches the range of matrix to [0, 255]
    """
    lo, hi = minmax_2d(matrix)
    return transform(matrix, lambda px: int((px - lo) / ((hi - lo) / 255)))


# task 4.2

def create_histogram(matrix):
    """
    counts the occurences of each value in the matrix
    """
    histogram = defaultdict(int)
    for row in matrix:
        for px in row:
            histogram[px] += 1

    return histogram


def normalize_histogram(histogram):
    """
    normalizes the values in a histogram, aka. creates a distribution histogram
    """
    normalized = dict()
    total = sum(histogram.values())
    for key, value in histogram.iteritems():
        normalized[key] = value / total

    return normalized


def create_cdf(normalized_histogram):
    """
    :returns a cummulative distribution function that can be called with a value parameter
    """
    return lambda i: sum(normalized_histogram[j] for j in [v for v in normalized_histogram.keys() if v <= i])


# task 5

def salt_and_pepper_noise(matrix, density):
    """
    :returns the matrix with some noise randomly added.
    Each noisy pixel will randomly be either black or white.
    The amount of noise increases with the parameter density
    """
    return transform(matrix, lambda px: np.random.randint(2) if np.random.random() < density else px)


# task 6

def alias(matrix, n):
    """
    Downscales the matrix by removing every row and column except every nth.
    """
    return np.asarray(
        [[px for x, px in enumerate(row) if x % n == 0] for y, row in enumerate(matrix) if y % n == 0]
    )