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


## Major classes
- `Image`: container for pixel data
- `Mosaic`: place on which you layout multiple tessarae
- `Tessera`: Each tesserae is abstraction of an image on mosaic
- `Shader`: basic shader to render data
- `Window`: for rendering
- `Renderer`: Has access to the shader and renders each tesserae by manipulating the base vertex buffer


## Usage

- Clone and build
```bash
git clone git@github.com:kvmanohar22/imgview.git
cd imgview
mkdir build
cd build
cmake ..
```

- Simple rendering

```c++
// Create (empty) mosaic and window
Mosaic* mosaic = new Mosaic();
Window* window = new Window(w, h, "viewer", mosaic);

// Load an image
Image* image = new Image("/path/to/image");

// Add the image to mosaic
const size_t start_x = 0;
const size_t start_y = 0;
const size_t width = w;
const size_t height = h;
mosaic->add_image(image, start_x, start_y, width, height);

// Render
window->show();

// do your stuff here. Rendering is in a separate thread
```
