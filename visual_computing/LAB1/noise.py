#! /usr/bin/python
import os

import matplotlib.pyplot as pl
import matplotlib.cm as cm
import numpy as np
from scipy.misc import lena
from scipy.misc.pilutil import imsave
from gamma import pixel_wise_transform

from flatfield import normalize_bw


OUTPUT_DIR = 'output/'


def salt_and_pepper_noise(matrix, density):
    return pixel_wise_transform(matrix, lambda px: np.random.randint(2) if np.random.random() < density else px)


def main():
    img_mat = np.asarray(normalize_bw(lena()))
    outputs = dict()
    for param in (0.1, 0.3, 0.8):
        outputs[param] = salt_and_pepper_noise(img_mat, param)
        file_name = 'noisy_{}.png'.format(str(param).replace('.', '_'))
        imsave(os.path.join(OUTPUT_DIR, file_name), outputs[param])

    pl.imshow(outputs[0.1], cmap=cm.Greys_r)
    pl.show()


if __name__ == "__main__":
    main()
