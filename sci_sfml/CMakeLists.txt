find_package( SFML
    COMPONENTS
        graphics
        system
        window
    REQUIRED
)

add_executable( sci_sfml )

target_include_directories( sci_sfml
    PUBLIC
        .
)

target_sources( sci_sfml
    PUBLIC
        ./main.cpp
)   

target_link_libraries( sci_sfml
    PRIVATE
        sfml-graphics
        sfml-system
        sfml-window
)