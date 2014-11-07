#! /usr/bin/python

from __future__ import print_function, division

import os

import matplotlib.cm as cm
import matplotlib.pyplot as pl
from scipy.misc import lena
from scipy.misc.pilutil import imread, imsave

from image_manipulation import *

OUTPUT_DIR = 'output/'
NASA = 'img/disturbed_potw1144a.png'
FLATFIELD = 'img/flatfieldimage.png'
EINSTEIN = 'img/einstein_lowcontrast.png'
BRICKS = 'img/bricks.png'


def task3():
    nasa_matrix = normalize_intensity(imread(NASA))
    flatfield_matrix = normalize_intensity(imread(FLATFIELD))

    corrected_image = correct_with_flatfield(nasa_matrix, flatfield_matrix)

    output_path = os.path.join(OUTPUT_DIR, os.path.split(NASA)[-1])
    imsave(output_path, corrected_image)
    pl.imshow(corrected_image, cmap=cm.Greys_r)
    pl.show()


def task4_1():
    einstein_matrix = imread(EINSTEIN)

    corrected = gamma_correct(einstein_matrix, gamma=1.5)
    output_path = os.path.join(OUTPUT_DIR, "gamma_" + os.path.split(EINSTEIN)[-1])
    imsave(output_path, corrected)

    stretched = stretch_range(einstein_matrix)
    corrected = gamma_correct(stretched, gamma=1.5)
    output_path = os.path.join(OUTPUT_DIR, "stretched_gamma_" + os.path.split(EINSTEIN)[-1])
    imsave(output_path, corrected)


def task4_2():
    matrix = random_matrix(4, 4, n=8)

    output_path = os.path.join(OUTPUT_DIR, 'original_matrix.png')
    imsave(output_path, matrix)

    histogram = create_histogram(matrix)
    normalized = normalize_histogram(histogram)
    cdf = create_cdf(normalized)
    image = transform(matrix, cdf)

    print(matrix)
    print(image)

    output_path = os.path.join(OUTPUT_DIR, 'normalized_matrix.png')
    imsave(output_path, image)
    pl.imshow(image, cmap=cm.Greys_r)
    pl.show()

    einstein = imread(EINSTEIN)
    ein_cdf = create_cdf(normalize_histogram(create_histogram(einstein)))
    imsave(os.path.join(OUTPUT_DIR, "cdf_" + os.path.split(EINSTEIN)[-1]), transform(einstein, ein_cdf))


def task5():
    img_mat = np.asarray(normalize_intensity(lena()))
    outputs = dict()
    for param in (0.1, 0.3, 0.8):
        outputs[param] = salt_and_pepper_noise(img_mat, param)
        file_name = 'noisy_{}.png'.format(str(param).replace('.', '_'))
        imsave(os.path.join(OUTPUT_DIR, file_name), outputs[param])

    pl.imshow(outputs[0.1], cmap=cm.Greys_r)
    pl.show()


def task6():
    imgs = ((BRICKS, 'bricks'), (lena(), 'lena'))
    for img, name in imgs:
        for n in (2, 3, 4):
            imsave('output/{}_down_{}x.png'.format(name, n), alias(img, n))

task3()
task4_1()
task4_2()
task5()
task6()