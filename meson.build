project('Moo', 'cpp', default_options : ['cpp_std=c++20'])

srcdir = 'src'
sources = [
  'src/library.cpp',
  'src/basics/factorial.cpp',
  'src/basics/binom.cpp',
  'src/basics/stdop.cpp',
  'src/basics/permutation.cpp'
]

dll_export = ['-DMOOLIB_BUILDING']

# Platform-specific configuration
if get_option('buildtype') == 'debug'
  dll_export += ['-DDEBUG']
endif

# Use consistent library name
output_name = 'Moo'

moo_lib = shared_library(
  output_name,
  sources,
  install : false,
  install_dir : 'lib',
  soversion : '1',
  version : '1.0.0'
)