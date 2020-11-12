# GK - Projekt 2

## Dependencies

* Qt5, preferably version 5.15

## Compilation

### Linux

The project can be compiled with Cmake (minimum version - 3.17), using the `CmakeLists.txt` file.
In order to build the project, Qt5 needs to be installed. It is recommended to install it from the distro's package manager.
After installing Qt, compile the project using command:

`cmake --build <output_dir> --target triangle_painter -- -j 6`.

## Usage

When the program is running, the picture can be controlled with the panel to the right.
It is possible to 
* change triangle grid size (the picture is updated after clicking _Reset grid_ button)
* reset triangle grid after moving vertices with the _Reset grid_ button
* change light color (by cliking on the color square) 
* change light vector (constant - [0,0,1], or computed according to animated light moving on spiral)
* change fill color (by clicking on the color square)
* choose fill texture and enable it by selecting the radio button
* change color determination way - the color can be computed precisely for every pixel, 
or interpolated from triangles' vertices
* change normal vector `N` (constant - [0,0,1], or obtained from chosen normal map)
* change parameters `kd`, `ks` and `m` (`kd` and `ks` sliders are bound together, so that always `kd = 1 - ks`)

In the folder `img`, there is one sample image to use as fill texture and one to use as a normal map.


## Remarks
