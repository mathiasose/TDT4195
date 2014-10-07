# TDT4195 LAB 4
# Mathias Ose

Multiplying MODEL_LEG_2 into MVP2 and MODEL_LEG_1 into MVP3 achieves the correct rotation of the hips.

To draw the legs differently, new datapoints had to be defined and those points rendered with glDrawArrays.

In order to color the different parts as instructed, different color_buffer_data buffers were created for each of the colors, then, like vertexbuffer, bound to it's own colorbuffer. Then for each body part the buffer in use was changed to the correct one with glBindBuffer.

For RenderScene6() all that had to be done was to ensure that the position vector, the same one as the keyboard movement buttons modify, is incremented at the same rate and dimension (Z-axis) as MODEL_EVERYTHING is translated. In other words, manually translating (by vector addition) the View matrix the same way the Model matrix is translated.
