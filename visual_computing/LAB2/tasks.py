from __future__ import print_function, division
from numpy import linspace
from numpy import log
from numpy.fft import fft2, fftshift, ifft2
from LAB1.image_manipulation import normalize_intensity, salt_and_pepper_noise
from LAB2.stuff import discrete_convolution, list_get, continuous_convolution, gaussian_noise, averaging_mask

import os

from scipy.misc.pilutil import imread, imsave

OUTPUT_DIR = os.path.join(os.path.dirname(__file__), 'output/')
CAMERAMAN = os.path.join(os.path.dirname(__file__), 'img/cameraman.png')
BRICKS = os.path.join(os.path.dirname(__file__), 'img/bricks_bw.png')
HIGH_PASS = os.path.join(os.path.dirname(__file__), 'img/high_pass.png')
LOW_PASS = os.path.join(os.path.dirname(__file__), 'img/low_pass.png')
BRICKS_2 = os.path.join(os.path.dirname(__file__), 'img/bricks_bw_256.png')


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
    img = normalize_intensity(imread(CAMERAMAN))
    gaussian = gaussian_noise(img, mean=0, std=0.1)
    peppered = salt_and_pepper_noise(img, density=0.25)

    output_path = os.path.join(OUTPUT_DIR, "2_1_gauss_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(gaussian, filter_size=5))

    output_path = os.path.join(OUTPUT_DIR, "2_1_pepper_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(peppered, filter_size=5))


def task2_2():
    img = normalize_intensity(imread(CAMERAMAN))
    gaussian = gaussian_noise(img, mean=0, std=0.1)
    peppered = salt_and_pepper_noise(img, density=0.25)

    output_path = os.path.join(OUTPUT_DIR, "2_2_gauss_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(gaussian, filter_size=5))

    output_path = os.path.join(OUTPUT_DIR, "2_2_pepper_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(peppered, filter_size=5))


def task3_1():
    c_img = normalize_intensity(imread(CAMERAMAN))
    fft_res = fft2(a=c_img)
    output_path = os.path.join(OUTPUT_DIR, "3_1_fft_spectrum_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, log(1 + abs(fftshift(fft_res))))

    b_img = normalize_intensity(imread(BRICKS))
    fft_res = fft2(a=b_img)
    output_path = os.path.join(OUTPUT_DIR, "3_1_fft_spectrum_" + os.path.split(BRICKS)[-1])
    imsave(output_path, log(1 + abs(fftshift(fft_res))))


def task3_2():
    low_pass = normalize_intensity(imread(LOW_PASS))
    high_pass = normalize_intensity(imread(HIGH_PASS))

    img_freq_dom = fft2(a=normalize_intensity(imread(BRICKS_2)))
    apply_low_pass = img_freq_dom * low_pass
    ifft_res = ifft2(a=apply_low_pass)
    output_path = os.path.join(OUTPUT_DIR, "3_2_low_pass_" + os.path.split(BRICKS_2)[-1])
    imsave(output_path, abs(ifft_res))

    apply_high_pass = img_freq_dom * high_pass
    ifft_res = ifft2(a=apply_high_pass)
    output_path = os.path.join(OUTPUT_DIR, "3_2_high_pass_" + os.path.split(BRICKS_2)[-1])


#task1_1()
#task1_2()
#task2_1()
#task2_2()
#task3_1()
task3_2()
