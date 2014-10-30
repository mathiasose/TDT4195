#! /usr/bin/python
import matplotlib.pyplot as pl
from numpy import asarray
from scipy.misc import lena
from scipy.misc.pilutil import imread, imsave


def alias(img_mat, factor):
    ret = []
    for y in range(len(img_mat)):
        if y % factor == 0:
            l = []
            for x in range(len(img_mat[0])):
                if x % factor == 0:
                    l.append(img_mat[y][x])
            ret.append(l)
    return asarray(ret)


def main():
    bricks_mat = lena()
    downsample_2x = alias(bricks_mat, 2)
    imsave('output/lena_down_2x.png', downsample_2x)
    downsample_3x = alias(bricks_mat, 3)
    imsave('output/lena_down_3x.png', downsample_3x)
    downsample_4x = alias(bricks_mat, 4)
    imsave('output/lena_down_4x.png', downsample_4x)

    pl.imshow(alias(bricks_mat, 2))
    pl.show()

main()
