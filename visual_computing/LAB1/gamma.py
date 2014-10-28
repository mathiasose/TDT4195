from __future__ import print_function, division
import os

import numpy as np
from scipy.misc.pilutil import imread, imsave


OUTPUT_DIR = 'output/'


def pixel_wise_transform(matrix, fun):
    '''
    applies fun(px) to every px in the 2d matrix
    '''
    return np.asarray(map(lambda row: map(lambda px: fun(px), row), matrix))


def minmax_2d(matrix):
    '''
    returns the minimum and maximum value of a 2d matrix
    '''
    return map(lambda f: f(f(matrix, key=lambda x: f(x))), (min, max))


def stretch_range(matrix):
    '''
    stretches the range of matrix to [0, 255]
    '''
    m_min, m_max = minmax_2d(matrix)
    return pixel_wise_transform(matrix, lambda px: int((px - m_min) / ((m_max - m_min) / 255)))


def gamma_correct(matrix, gamma=1.0):
    '''
    applies the gamma correction function (px)^(gamma) to the matrix
    '''
    return pixel_wise_transform(matrix, lambda px: int(255 * ((px / 255) ** gamma)))


def main():
    EINSTEIN = 'img/einstein_lowcontrast.png'

    einstein_matrix = imread(EINSTEIN)
    stretched = stretch_range(einstein_matrix)
    corrected = gamma_correct(stretched, gamma=1.5)

    output_path = os.path.join(OUTPUT_DIR, os.path.split(EINSTEIN)[-1])
    imsave(output_path, corrected)


if __name__ == "__main__":
    main()
