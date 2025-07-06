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

# Platform-specific arguments
extra_args = {}
if host_machine.system() == 'windows'
  extra_args += {'vs_module_defs': []}
endif

moo_lib = shared_library(
  output_name,
  sources,
  cpp_args : dll_export,
  install : false,
  kwargs : extra_args,
)