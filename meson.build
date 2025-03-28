project(
  'c-pong', 
  'c',
  version : '0.1',
  default_options : ['warning_level=3']
)

dependencies = [
  dependency('inih', required: true),
  dependency('raylib', required: true)
]
include_directories = [
  './include'
]
sources = [
  './src/main.c',
  './src/settings.c',
  './src/layout.c'
]

executable(
  'c-pong',
  sources: sources,
  include_directories: include_directories,
  dependencies: dependencies
)
