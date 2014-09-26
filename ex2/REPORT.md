# TDT4195 LAB 2
# Mathias Ose

When scene 5 is activated, the shaders are applied. This application affects all the scenes. The shader includes a repositioning of the viewpoint, therefore when you go back to other scenes you see it from another, quite awkward angle and distance..

The color of the triangle is defined by the shader. vec3(1,1,0) means 100% Red, 100% Green, 0% Blue, which makes a yellow composite color.

The triangle is defined by the datapoints in g_vertex_buffer_data. Mirroring the existing triangle on the Y-axis gives a triangle with a vertex in the top left.

Adding more shapes is just a matter of adding more data to g_vertex_buffer_data. Instead of trying to make up datapoints I made a simple Python script to generate some valid data and copied that output into the C++ program.
