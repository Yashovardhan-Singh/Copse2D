renderer_sources = files(
    'renderer.c',
    'texture.c',
    'shaders.c',
    'render_objects.c',
    'render_context.c',
    'render_batch.c',
    'camera.c'
)

renderer_includes = include_directories(
    '.'
)

renderer = declare_dependency(
    sources: renderer_sources,
    include_directories: renderer_includes
)