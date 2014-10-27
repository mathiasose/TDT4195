#! /usr/bin/python

from __future__ import print_function, division
from copy import deepcopy
import os

from scipy.misc.pilutil import imread, imsave

import matplotlib.pyplot as pl
import matplotlib.cm as cm


OUTPUT_DIR = 'output/'


def normalize_bw(img_matrix):
    return map(lambda row: map(lambda val: val / 255, row), img_matrix)


def correct_with_flatfield(img, flatfield):
    corrected = deepcopy(img)
    for y, (a_row, b_row) in enumerate(zip(img, flatfield)):
        for x, (a_px, b_px) in enumerate(zip(a_row, b_row)):
            corrected[y][x] = a_px / b_px

    return corrected


def main():
    NASA = 'img/disturbed_potw1144a.png'
    FLATFIELD = 'img/flatfieldimage.png'

    nasa_matrix = normalize_bw(imread(NASA))
    flatfield_matrix = normalize_bw(imread(FLATFIELD))

    corrected_image = correct_with_flatfield(nasa_matrix, flatfield_matrix)

    output_path = os.path.join(OUTPUT_DIR, os.path.split(NASA)[-1])
    imsave(output_path, corrected_image)
    pl.imshow(corrected_image, cmap=cm.Greys_r)
    pl.show()

if __name__ == "__main__":
    main()
