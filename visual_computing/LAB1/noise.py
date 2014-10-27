#! /usr/bin/python

import matplotlib.pyplot as pl
import matplotlib.cm as cm
import numpy.random
from copy import deepcopy
from scipy.misc import lena
from scipy.misc.pilutil import imsave
from flatfield import normalize_bw


def salt_and_pepper_noise(image, density):
    ret = deepcopy(image)
    for y in range(len(image)):
        for x in range(len(image[0])):
            rnd = numpy.random.random()
            if rnd < density:
                ret[y][x] = numpy.random.randint(2)
    return ret


def main():
    img_mat = numpy.asarray(normalize_bw(lena()))
    noisy_0_1 = salt_and_pepper_noise(img_mat, 0.1)
    imsave('output/noisy_0_1.png', noisy_0_1)
    noisy_0_3 = salt_and_pepper_noise(img_mat, 0.3)
    imsave('output/noisy_0_3.png', noisy_0_3)
    noisy_0_8 = salt_and_pepper_noise(img_mat, 0.8)
    imsave('output/noisy_0_8.png', noisy_0_8)
    pl.imshow(noisy_0_1, cmap=cm.Greys_r)
    pl.show()

if __name__ == "__main__":
    main()
