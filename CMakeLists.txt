cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto sin espacios
project(ConversorGP9 VERSION 1.0.0 LANGUAGES CXX)

# -------------------------------------------------------------
# COMPILACIÓN ESTÁTICA EN WINDOWS (SIN DLLs)
# -------------------------------------------------------------
if(MSVC)
    # Forzar /MT o /MTd (no usar DLLs del runtime)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# -------------------------------------------------------------
# CONFIGURACIÓN GENERAL DEL PROYECTO
# -------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Si no se especifica tipo, usar Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# -------------------------------------------------------------
# OPTIMIZACIÓN MULTIPLATAFORMA
# -------------------------------------------------------------
if (MSVC)
#CONFIGUARACIÓN EXCLUSIVA PARA WINDOWS
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od")
else ()
#CONFIGURACIONES EXCLUSIVAS PARA LINUX Y MacOS
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
endif()

# -------------------------------------------------------------
# INCLUDES
# -------------------------------------------------------------
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# -------------------------------------------------------------
# LIBRERÍA DEL CONVERSOR
# -------------------------------------------------------------
add_library(ConversorLib STATIC
    src/Conversor.cpp
)

# -------------------------------------------------------------
# EJECUTABLE PRINCIPAL (ubicado en /examples)
# -------------------------------------------------------------
add_executable(TestConversor
    examples/main.cpp
)

# Enlazar el ejecutable con la biblioteca
target_link_libraries(TestConversor PRIVATE ConversorLib)

# COMPILACIÓN ESTÁTICA EN LINUX (Inyectar librerías al ejecutable)
if(NOT MSVC AND CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_options(TestConversor PRIVATE -static-libgcc -static-libstdc++ -static)
endif()

# -------------------------------------------------------------
# INSTALACIÓN (OPCIONAL)
# -------------------------------------------------------------
install(TARGETS ConversorLib ARCHIVE DESTINATION lib)
install(TARGETS TestConversor RUNTIME DESTINATION bin)
install(DIRECTORY include/ DESTINATION include)

# -------------------------------------------------------------
# MENSAJES EN CONSOLA
# -------------------------------------------------------------
message(STATUS "==============================================")
message(STATUS " Proyecto ConversorGP9 configurado correctamente")
message(STATUS " Compilación estática activada para Windows y Linux")
message(STATUS " Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "==============================================")
