find_package(PkgConfig)

# disable pkg-config default functionality of printing additional cl options
set(ENV{PKG_CONFIG_ALLOW_SYSTEM_CFLAGS} 1)
set(ENV{PKG_CONFIG_ALL_SYSTEM_LIBS} 1)

# Try to find FFTW3 using pkg-config
pkg_search_module(FFTW3 REQUIRED fftw3 IMPORTED_TARGET GLOBAL)