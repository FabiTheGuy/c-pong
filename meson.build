project(
  'c-pong', 
  'c',
  version : '0.1',
  default_options : ['warning_level=3', 'buildtype=debug']
)

dependencies = [
  dependency('inih', required: true),
  dependency('raylib', required: true)
]
include_directories = [
  include_directories('./include'),
  include_directories('./include/ui'),
  include_directories('./include/utils'),
]
sources = [
  './src/main.c',
  './src/ui/button.c',
  './src/ui/drop-down.c',
  './src/ui/label.c',
  './src/ui/layout.c',
  './src/ui/main-menu.c',
  './src/state_manager.c',
  './src/utils/settings.c',
  './src/utils/utils.c',
]

executable(
  'c-pong',
  sources: sources,
  include_directories: include_directories,
  dependencies: dependencies,
  link_args: ['-lm'],
)
