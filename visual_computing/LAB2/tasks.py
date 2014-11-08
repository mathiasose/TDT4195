from __future__ import print_function, division
import os

from numpy import linspace
from numpy import log
from numpy.fft import fft2, fftshift, ifft2
from scipy.misc.pilutil import imread, imsave
from scipy.ndimage.filters import gaussian_filter

from LAB1.image_manipulation import normalize_intensity, salt_and_pepper_noise, alias
from LAB2.stuff import discrete_convolution, list_get, continuous_convolution, gaussian_noise, averaging_mask, \
    gauss_filter, gauss_kernel


DIR = os.path.dirname(__file__)
OUTPUT_DIR = os.path.join(DIR, 'output/')
CAMERAMAN = os.path.join(DIR, 'img/cameraman.png')
BRICKS = os.path.join(DIR, 'img/bricks_bw.png')
HIGH_PASS = os.path.join(DIR, 'img/high_pass.png')
LOW_PASS = os.path.join(DIR, 'img/low_pass.png')
BRICKS_2 = os.path.join(DIR, 'img/bricks_bw_256.png')


def task1_1():
    print('1.1')
    F = [1, 1, 1, 1, 1]
    G = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0]
    f = lambda n: list_get(F, n)
    g = lambda n: list_get(G, n)

    r = len(F) // 2
    D = range(-r, r)

    print(map(discrete_convolution(f, g, D), xrange(len(G))))


def task1_2():
    print('1.2')
    f = g = lambda t: 0 if abs(t) > .5 else 1

    values = linspace(-1, 1, 9)
    convoluted = map(continuous_convolution(f, g), values)
    rounded = map(lambda x: round(x, 1), convoluted)
    print(zip(values, rounded))


def task2_1():
    print('2.1')
    img = normalize_intensity(imread(CAMERAMAN))
    gaussian = gaussian_noise(img, mean=0, std=0.1)
    peppered = salt_and_pepper_noise(img, density=0.25)

    output_path = os.path.join(OUTPUT_DIR, "2_1_gauss_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(gaussian, filter_size=5))

    output_path = os.path.join(OUTPUT_DIR, "2_1_pepper_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(peppered, filter_size=5))


def task2_2():
    print('2.2')
    img = normalize_intensity(imread(CAMERAMAN))
    gaussian = gaussian_noise(img, mean=0, std=0.1)
    peppered = salt_and_pepper_noise(img, density=0.25)

    output_path = os.path.join(OUTPUT_DIR, "2_2_gauss_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(gaussian, filter_size=5))

    output_path = os.path.join(OUTPUT_DIR, "2_2_pepper_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, averaging_mask(peppered, filter_size=5))


def task2_3():
    print('2.3')
    img = normalize_intensity(imread(BRICKS))

    img = gauss_filter(img, 0.8)
    img = alias(img, 4)

    output_path = os.path.join(OUTPUT_DIR, "2_3_" + os.path.split(BRICKS)[-1])
    imsave(output_path, img)


def task3_1():
    print('3.1')
    c_img = normalize_intensity(imread(CAMERAMAN))
    fft_res = fft2(a=c_img)
    output_path = os.path.join(OUTPUT_DIR, "3_1_fft_spectrum_" + os.path.split(CAMERAMAN)[-1])
    imsave(output_path, log(1 + abs(fftshift(fft_res))))

    b_img = normalize_intensity(imread(BRICKS))
    fft_res = fft2(a=b_img)
    output_path = os.path.join(OUTPUT_DIR, "3_1_fft_spectrum_" + os.path.split(BRICKS)[-1])
    imsave(output_path, log(1 + abs(fftshift(fft_res))))


def task3_2():
    print('3.2')
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


# task1_1()
# task1_2()
# task2_1()
# task2_2()
task2_3()
# task3_1()
# task3_2()
