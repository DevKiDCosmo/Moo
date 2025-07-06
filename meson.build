project('Moo', 'cpp', default_options : ['cpp_std=c++23'])

srcdir = 'src'
sources = [
  'src/library.cpp',
  'src/basics/factorial.cpp',
  'src/basics/binom.cpp',
  'src/basics/stdop.cpp',
  'src/basics/permutation.cpp'
]

dll_export = ['-DEXPORTING_DLL']

if get_option('buildtype') == 'debug'
  dll_export += ['-DDEBUG']
  output_name = 'Moo'
else
  output_name = 'MooMeson'
endif

moo_lib = shared_library(
  output_name,
  sources,
  cpp_args : dll_export,
  install : false,
)