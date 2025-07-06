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

# Platform-specific configuration
host_system = host_machine.system()
if host_system == 'windows'
  dll_export += ['-DMOOLIB_EXPORTS']
elif host_system in ['linux', 'darwin', 'freebsd', 'openbsd', 'netbsd', 'dragonfly', 'sunos', 'cygwin']
  # Unix-based systems with symbol visibility
  if get_option('default_library') == 'shared'
    dll_export += ['-fvisibility=hidden']
  endif
endif

if get_option('buildtype') == 'debug'
  dll_export += ['-DDEBUG']
endif

# Use consistent library name
output_name = 'Moo'

moo_lib = shared_library(
  output_name,
  sources,
  cpp_args : dll_export,
  install : false,
  install_dir : 'lib',
  soversion : '1',
  version : '1.0.0'
)