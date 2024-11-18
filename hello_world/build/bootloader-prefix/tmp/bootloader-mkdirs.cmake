# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/rafae/esp/v5.3.1/esp-idf/components/bootloader/subproject"
  "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader"
  "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix"
  "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix/tmp"
  "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix/src"
  "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/RafaelDias/Microcontroladores/ESP-IDF_Curso/hello_world/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
