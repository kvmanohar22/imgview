# ImgView

## Requirements
- OpenGL 3.3
- glfw3 (for window management)
- gl3w (for window management)
- glm (for opengl math)
- stb_image (for image I/O)

Place gl3w headers (`gl3w.h`, `glcorearb.h`) under `include/imgview/ext/gl3w`, `stb_image.h` under `include/imgview/` and `glw3.c` under `src`.


## Usage
```bash
git clone git@github.com:kvmanohar22/imgview.git
cd imgview
mkdir build
cd build
cmake ..
make test_pipeline
./test_pipeline
```

