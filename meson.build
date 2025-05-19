project(
  'Copse2D', 'c',
  version: '0.1.0',
  default_options: [
    'c_std=c11',
    'default_library=both'
  ],
)

cc = meson.get_compiler('c')

subdir('vendor/tomlc')
subdir('vendor/glad')
subdir('vendor/stb_image')

subdir('src')

glfw = dependency('glfw3', required: true)
math = cc.find_library('m')

Copse2D_deps = [
  glad,
  stb_image,
  tomlc,
  glfw,
  math
]

Copse2D = library(
  'Copse2D',
  Copse2D_sources,
  include_directories: Copse2D_includes,
  dependencies: Copse2D_deps
)

subdir('example')
