project('c-pong', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

ray_dep = dependency('raylib')

exe = executable('c-pong',
  install : true, 
  sources: ['src/main.c', 'src/renderer.c'],
  include_directories: include_directories('include'),
  dependencies : [ray_dep])

test('basic', exe)
