# TDT4195 LAB 2
# Øyvind Robertsen

## Part 1

Upon switching to scene 5, the shaders are applied to the OpenGL context as a whole. Part of the shader code changes the positioning, thus when you go back to the previous scenes you see them from a different angle, much closer.

## Part 2/3

The color of the triangle comes from the shader. Changing the shader to `vec3(1,1,0)` makes it yellow.

The triangle is defined by the coordinates in g_vertex_buffer_data. To get one vertex into the top right I simply mirrored the existing triangle on the Y axis.

To plot more triangles I added more datapoints to g_vertex_buffer_data, and made RenderScene6 render all the values after the first three (the ones rendered by scene 5). The datapoints were generated by a Python script (because I couldn't quite grok the equivalent C++).