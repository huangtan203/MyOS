project(kernel LANGUAGES C)

set(CMAKE_EXE_LINKER_FLAGS "-m elf_i386 -T ${PROJECT_SOURCE_DIR}/kernel.lds")
#PROJECT_SOURCE_DIR当前camke所在的目录
set(CMAKE_C_LINK_EXECUTABLE "${LINKER_TOOL} <OBJECTS> ${CMAKE_EXE_LINKER_FLAGS} -o ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.elf")
#如果您没有在执行cmake命令时显式指定构建目录，那么CMake会默认将构建目录设置为源代码目录下的build子目录。
#具体而言，默认情况下，PROJECT_BINARY_DIR的默认值将是 <path-to-source>/build，其中<path-to-source>是执行cmake命令时指定的源代码目录路径。
file(GLOB_RECURSE C_LIST "*.c" "*.h" "*.S")
add_executable(${PROJECT_NAME}  ${C_LIST})
add_custom_command(TARGET ${PROJECT_NAME} 
POST_BUILD
    COMMAND ${OBJCOPY_TOOL} -S ${PROJECT_NAME}.elf ${CMAKE_SOURCE_DIR}/../../image/${PROJECT_NAME}.elf
    COMMAND ${OBJDUMP_TOOL} -x -d -S -m i386 ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.elf > ${PROJECT_NAME}_dis.txt
    COMMAND ${READELF_TOOL} -a ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.elf > ${PROJECT_NAME}_elf.txt)
#在CMake中，默认情况下，以下几个目录变量具有以下默认值：
#PROJECT_SOURCE_DIR`：默认情况下，它指向包含CMakeLists.txt文件的目录，即项目的根目录。
#PROJECT_BINARY_DIR`：默认情况下，它会根据执行`cmake`命令时显式指定的构建目录来设置，如果没有指定，则采用默认值 `<path-to-source>/build`。其中，`<path-to-source>`是执行`cmake`命令时指定的源代码目录路径。
#CMAKE_CURRENT_SOURCE_DIR`：默认指向当前源文件所在的目录。
#CMAKE_CURRENT_BINARY_DIR`：默认指向当前正在进行构建的目标所在的目录。
#这些目录变量的默认值可以随着执行`cmake`命令时的参数和设置而有所不同。如果需要确切的默认值，请参考您使用的具体构建系统和CMake版本的文档或官方资源。