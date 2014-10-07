# TDT4195 LAB 3
# Mathias Ose

There doesn't seem to be a lot to write a report about in this lab.

All the RenderScenes were based on the scene 4 provided,
the only thing needed to do was to add more datapoints to g_vertex_buffer_data and increase the number of datapoints glDrawArrays() draws.

Rotation and translation for all scenes is handled in Idle().
Translation direction is reversed once 500ms has passed since last reversing, for both cases.
