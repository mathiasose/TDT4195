from __future__ import print_function, division

import os

from scipy.misc.pilutil import imread, imsave

OUTPUT_DIR = 'output/'


def normalize_bw(img_matrix):
    img_matrix = map(lambda row: map(lambda val: round(float(val) / 255.0, 2), row), img_matrix)
    return img_matrix


def correct_with_flatfield(img, flatfield):
    for a_row, b_row in zip(img, flatfield):
        for a_px, b_px in zip(a_row, b_row):
            a_px /= b_px

    return img


def main():
    NASA = 'img/disturbed_potw1144a.png'
    FLATFIELD = 'img/flatfieldimage.png'

    nasa_matrix = normalize_bw(imread(NASA))
    flatfield_matrix = normalize_bw(imread(FLATFIELD))

    correct_with_flatfield(nasa_matrix, flatfield_matrix)

    output_path = os.path.join(OUTPUT_DIR, os.path.split(NASA)[-1])
    imsave(output_path, nasa_matrix)


main()