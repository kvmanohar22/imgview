# ImgView
Non-blocking image viewer written in C++ using OpenGL

<p align="center"><img width="70%" height="70%" src="imgs/img2.png"/></p>

## Requirements
- OpenGL 3.3
- glfw3 (for window management)
- gl3w (for window management)
- glm (for opengl math)
- stb_image (for image I/O)

Place gl3w headers (`gl3w.h`, `glcorearb.h`) under `include/imgview/ext/gl3w`, `stb_image.h` under `include/imgview/` and `glw3.c` under `src`.


## Usage

- Clone and build
```bash
git clone git@github.com:kvmanohar22/imgview.git
cd imgview
mkdir build
cd build
cmake ..
```
