from __future__ import division, print_function

from numpy.core.numeric import Inf
from numpy.random.mtrand import normal
from scipy.integrate.quadpack import quad
import numpy as np
from scipy.ndimage.filters import gaussian_filter
from math import pi

from LAB1.image_manipulation import transform, alias


def list_get(li, i, pad_with=0):
    return li[i] if 0 <= i < len(li) else pad_with


def matrix_get(matrix, x, y, pad_with=0):
    if not (0 <= y < len(matrix)):
        return pad_with

    return list_get(matrix[y], x, pad_with=pad_with)


def truncate_range(val, lo=0, hi=1):
    return max(lo, min(hi, val))


def get_neighbourhood(matrix, x, y, d=1):
    xs = xrange(x - d, x + d)
    ys = xrange(y - d, y + d)
    neighbours = [matrix_get(matrix, i, j, pad_with=None) for i in xs for j in ys]
    neighbours = filter(lambda n: n is not None, neighbours)
    return neighbours


def average(li):
    return float(sum(li)) / len(li)


def median(li):
    li = sorted(li)
    m = len(li) // 2
    if len(li) % 2 == 0:
        return average([li[m], li[m + 1]])

    return li[m]


def transform_by_coordinate(matrix, fun):
    return np.asarray([[fun(x, y) for x, _ in enumerate(row)] for y, row in enumerate(matrix)])




# Task 1
def discrete_convolution(f, g, D):
    return lambda n: sum((f(k) * g(n - k)) for k in D)


def continuous_convolution(f, g):
    return lambda t: quad(lambda v: (f(v) * g(t - v)), -Inf, Inf)[0]


# Task 2
def gaussian_noise(matrix, mean=0, std=0.1):
    return transform(matrix, lambda px: truncate_range(px + normal(loc=mean, scale=std)))


def averaging_mask(matrix, filter_size=3):
    if filter_size < 3:
        filter_size = 3

    d = filter_size // 2
    f = lambda x, y: average(get_neighbourhood(matrix, x, y, d=d))
    return transform_by_coordinate(matrix, f)


def median_mask(matrix, filter_size=3):
    if filter_size < 3:
        filter_size = 3

    d = filter_size // 2
    f = lambda x, y: median(get_neighbourhood(matrix, x, y, d=d))
    return transform_by_coordinate(matrix, f)


def convolution_2d(f, g, D_x, D_y):
    return lambda x, y: sum(sum(f(x, y) * g(n_x, n_y) for n_x in D_x) for n_y in D_y)


def gauss_kernel(size, sigma):
    x, y = np.mgrid[-size:size + 1, -size:size + 1]
    g = (1 / (2 * pi * sigma**2)) * np.exp(-(x ** 2 / size + y ** 2 / size) / (2 * sigma**2))
    return g / g.sum()


def gauss_filter(matrix, sigma):
    # kernel = gauss_kernel(2, sigma)
    # f = lambda x, y: matrix_get(matrix, x, y)
    # g = lambda x, y: matrix_get(kernel, x, y)
    # # r = len(kernel) // 2
    # # D = range(-r, r)  # D_1 == D_2 for square pictures
    # return transform_by_coordinate(matrix, convolution_2d(f, g, range(len(kernel[0])), range(len(kernel))))

    return gaussian_filter(matrix, sigma)
