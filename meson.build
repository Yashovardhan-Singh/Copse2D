project('Copse2D', 'c',
  version: '0.1.0',
  default_options: ['c_std=c11']
)

cc = meson.get_compiler('c')

subdir('src/window')
subdir('src/renderer')
subdir('src/gmath')

subdir('vendor/tomlc')
subdir('vendor/glad')
subdir('vendor/stb_image')

glfw = dependency('glfw3', required: true)
math = cc.find_library('m')

executable(
  'example',
  'example/example.c',
  dependencies: [window, renderer, math, stb_image, tomlc, glad, glfw]
)
