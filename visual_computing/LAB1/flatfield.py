#! /usr/bin/python

from __future__ import print_function, division

import os

import matplotlib.pyplot as pl
import matplotlib.cm as cm
from numpy import divide
from scipy.misc.pilutil import imread, imsave

OUTPUT_DIR = 'output/'


def normalize_bw(img_matrix):
    img_matrix = map(lambda row: map(lambda val: float(val) / 255.0, row), img_matrix)
    return img_matrix


def correct_with_flatfield(img, flatfield):
    return divide(img, flatfield)


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
