project('c-pong', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

ray_dep = dependency('raylib')

exe = executable('c-pong', 'main.c', 'renderer.c',
  install : true, dependencies : ray_dep)

test('basic', exe)
