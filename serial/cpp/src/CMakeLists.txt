add_executable(
    schrodinger 
    main.cpp
    grid.cpp
    potential.cpp 
    wavepacket.cpp
    solver.cpp
    )
target_link_libraries(schrodinger PRIVATE PkgConfig::FFTW3)