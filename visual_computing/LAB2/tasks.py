from __future__ import print_function, division
from numpy import linspace
from LAB1.image_manipulation import minmax_2d, normalize_intensity, salt_and_pepper_noise
from LAB2.stuff import discrete_convolution, list_get, continuous_convolution, gaussian_noise, averaging_mask

import os

import matplotlib.cm as cm
import matplotlib.pyplot as pl
from scipy.misc import lena
from scipy.misc.pilutil import imread, imsave

OUTPUT_DIR = 'output/'


def task1_1():
    F = [1, 1, 1, 1, 1]
    G = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0]
    f = lambda n: list_get(F, n)
    g = lambda n: list_get(G, n)

    r = len(F) // 2
    D = range(-r, r)

    print(map(discrete_convolution(f, g, D), xrange(len(G))))


def task1_2():
    f = lambda t: 0 if abs(t) > .5 else 1
    g = f

    print(map(continuous_convolution(f, g), linspace(-1, 1, 9)))


def task2_1():
    CAMERAMAN = 'img/cameraman.png'
    img = normalize_intensity(imread(CAMERAMAN))
    gaussian = gaussian_noise(img, mean=0, std=0.1)
    peppered = salt_and_pepper_noise(img, density=0.25)

    output_path = os.path.join(OUTPUT_DIR, "2_1_gauss_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(gaussian, filter_size=5))

    output_path = os.path.join(OUTPUT_DIR, "2_1_pepper_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(peppered, filter_size=5))


def task2_2():
    CAMERAMAN = 'img/cameraman.png'
    img = normalize_intensity(imread(CAMERAMAN))
    gaussian = gaussian_noise(img, mean=0, std=0.1)
    peppered = salt_and_pepper_noise(img, density=0.25)

    output_path = os.path.join(OUTPUT_DIR, "2_2_gauss_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(gaussian, filter_size=5))

    output_path = os.path.join(OUTPUT_DIR, "2_2_pepper_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(peppered, filter_size=5))

task1_1()
task1_2()
task2_1()
task2_2()