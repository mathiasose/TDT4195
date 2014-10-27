#! /usr/bin/python

import matplotlib.pyplot as pl
import matplotlib.cm as cm
import numpy.random
from scipy.misc.pilutil import imread
from flatfield import normalize_bw


def main():
    IMG = 'img/task5.png'

    img_mat = imread(IMG)
    print(img_mat)
    noisy = img_mat + numpy.random.random(img_mat.shape)

    pl.imshow(noisy, cmap=cm.Greys_r)
    pl.show()

if __name__ == "__main__":
    main()
