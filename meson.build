project('Moo', 'cpp', default_options : ['cpp_std=c++20'])

srcdir = 'src'
sources = [
  'src/library.cpp',
  'src/basics/factorial.cpp',
  'src/basics/binom.cpp',
  'src/basics/stdop.cpp',
  'src/basics/permutation.cpp'
]

dll_export = ['-DEXPORTING_DLL']

output_name = 'Moo'

moo_lib = shared_library(
  output_name,
  sources,
  cpp_args : dll_export,
  install : false,
  vs_module_defs : [],
)

moo_lib.set_output_dir(meson.project_build_root() / 'lib')
moo_lib.set_rpath(meson.project_build_root() / 'lib')