add_executable(2025_03_13_zad_44)
target_sources(2025_03_13_zad_44 PUBLIC ./main.cpp)

set(THIRD_PARTY_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/skrot_przyklad.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/skrot.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/skrot2_przyklad.txt
    ${CMAKE_CURRENT_SOURCE_DIR}/skrot2.txt
)

foreach(fi ${THIRD_PARTY_FILES})
    add_custom_command(
        TARGET 2025_03_13_zad_44 POST_BUILD
        COMMAND ${CMAKE_COMMAND}
        ARGS -E copy ${fi} ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach(fi)
