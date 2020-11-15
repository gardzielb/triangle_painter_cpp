# GK - Projekt 2

## Dependencies

* [Qt5](https://www.qt.io/)
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)

## Compilation

The project can be built with Cmake (minimum version 3.5) and it is possible to compile it both on Linux (using g++ compiler) and Windows with MSVC compiler. However, the recommended way is to use Linux and follow instructions below.

### Installing dependencies

* **Qt**: it is recommended to isntall Qt5 from the distro's package manager, such as apt.
* **Eigen**: Eigen can be installed using one of the links [here](http://eigen.tuxfamily.org/index.php?title=Main_Page). The recommended way is to clone git repository. In order to make Eigen headers visible to the project files, create a symlink in `/usr/local/include` directory, pointing to `<path-to-eigen-repository>/Eigen/`.

### Cmake build

Create directory for build output and `cd` into it. Then run the following commands.

`cmake -DCMAKE_BUILD_TYPE=Release /full/path/to/triangle_painter/`

`cmake --build <output_dir> --target triangle_painter -- -j 6`

The executable file will be created in output directory.

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
