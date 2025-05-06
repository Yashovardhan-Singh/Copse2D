project('Copse2D', 'c',
  version: '0.1.0',
  default_options: ['c_std=c11']
)

subdir('src/window')
subdir('src/renderer')

subdir('vendor/tomlc')
subdir('vendor/glad')

glfw = dependency('glfw3', required: true)

executable(
  'example',
  'example/example.c',
  dependencies: [window, tomlc, glad, glfw]
)