# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build

# Include any dependencies generated for this target.
include source/kernel/CMakeFiles/kernel.dir/depend.make

# Include the progress variables for this target.
include source/kernel/CMakeFiles/kernel.dir/progress.make

# Include the compile flags for this target's objects.
include source/kernel/CMakeFiles/kernel.dir/flags.make

source/kernel/CMakeFiles/kernel.dir/init/start.S.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/init/start.S.obj: ../source/kernel/init/start.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building ASM object source/kernel/CMakeFiles/kernel.dir/init/start.S.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/kernel.dir/init/start.S.obj -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/init/start.S

source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.requires

source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.provides: source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.provides

source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/init/start.S.obj


source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj: ../source/kernel/cpu/cpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/cpu/cpu.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/cpu/cpu.c

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cpu/cpu.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/cpu/cpu.c > CMakeFiles/kernel.dir/cpu/cpu.c.i

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cpu/cpu.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/cpu/cpu.c -o CMakeFiles/kernel.dir/cpu/cpu.c.s

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj


source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj: ../source/kernel/cpu/irq.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/cpu/irq.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/cpu/irq.c

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/cpu/irq.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/cpu/irq.c > CMakeFiles/kernel.dir/cpu/irq.c.i

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/cpu/irq.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/cpu/irq.c -o CMakeFiles/kernel.dir/cpu/irq.c.s

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj


source/kernel/CMakeFiles/kernel.dir/init/init.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/init/init.c.obj: ../source/kernel/init/init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object source/kernel/CMakeFiles/kernel.dir/init/init.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/init/init.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/init/init.c

source/kernel/CMakeFiles/kernel.dir/init/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/init/init.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/init/init.c > CMakeFiles/kernel.dir/init/init.c.i

source/kernel/CMakeFiles/kernel.dir/init/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/init/init.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/init/init.c -o CMakeFiles/kernel.dir/init/init.c.s

source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/init/init.c.obj


source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj: ../source/kernel/dev/time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/dev/time.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/dev/time.c

source/kernel/CMakeFiles/kernel.dir/dev/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/dev/time.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/dev/time.c > CMakeFiles/kernel.dir/dev/time.c.i

source/kernel/CMakeFiles/kernel.dir/dev/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/dev/time.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/dev/time.c -o CMakeFiles/kernel.dir/dev/time.c.s

source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj


source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj: ../source/kernel/dev/console.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/dev/console.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/dev/console.c

source/kernel/CMakeFiles/kernel.dir/dev/console.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/dev/console.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/dev/console.c > CMakeFiles/kernel.dir/dev/console.c.i

source/kernel/CMakeFiles/kernel.dir/dev/console.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/dev/console.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/dev/console.c -o CMakeFiles/kernel.dir/dev/console.c.s

source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj


source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj: ../source/kernel/ipc/mutex.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/ipc/mutex.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/ipc/mutex.c

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/ipc/mutex.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/ipc/mutex.c > CMakeFiles/kernel.dir/ipc/mutex.c.i

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/ipc/mutex.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/ipc/mutex.c -o CMakeFiles/kernel.dir/ipc/mutex.c.s

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj


source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj: ../source/kernel/ipc/sem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/ipc/sem.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/ipc/sem.c

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/ipc/sem.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/ipc/sem.c > CMakeFiles/kernel.dir/ipc/sem.c.i

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/ipc/sem.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/ipc/sem.c -o CMakeFiles/kernel.dir/ipc/sem.c.s

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj


source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj: ../source/kernel/tools/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/tools/log.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/log.c

source/kernel/CMakeFiles/kernel.dir/tools/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/log.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/log.c > CMakeFiles/kernel.dir/tools/log.c.i

source/kernel/CMakeFiles/kernel.dir/tools/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/log.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/log.c -o CMakeFiles/kernel.dir/tools/log.c.s

source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj


source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj: ../source/kernel/tools/bitmap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/tools/bitmap.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/bitmap.c

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/bitmap.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/bitmap.c > CMakeFiles/kernel.dir/tools/bitmap.c.i

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/bitmap.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/bitmap.c -o CMakeFiles/kernel.dir/tools/bitmap.c.s

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj


source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj: ../source/kernel/tools/klib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/tools/klib.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/klib.c

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/klib.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/klib.c > CMakeFiles/kernel.dir/tools/klib.c.i

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/klib.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/klib.c -o CMakeFiles/kernel.dir/tools/klib.c.s

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj


source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj: ../source/kernel/tools/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/tools/list.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/list.c

source/kernel/CMakeFiles/kernel.dir/tools/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/tools/list.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/list.c > CMakeFiles/kernel.dir/tools/list.c.i

source/kernel/CMakeFiles/kernel.dir/tools/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/tools/list.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/tools/list.c -o CMakeFiles/kernel.dir/tools/list.c.s

source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj


source/kernel/CMakeFiles/kernel.dir/core/task.c.obj: source/kernel/CMakeFiles/kernel.dir/flags.make
source/kernel/CMakeFiles/kernel.dir/core/task.c.obj: ../source/kernel/core/task.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object source/kernel/CMakeFiles/kernel.dir/core/task.c.obj"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kernel.dir/core/task.c.obj   -c /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/core/task.c

source/kernel/CMakeFiles/kernel.dir/core/task.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kernel.dir/core/task.c.i"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/core/task.c > CMakeFiles/kernel.dir/core/task.c.i

source/kernel/CMakeFiles/kernel.dir/core/task.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kernel.dir/core/task.c.s"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && /usr/bin/gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel/core/task.c -o CMakeFiles/kernel.dir/core/task.c.s

source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.requires:

.PHONY : source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.requires

source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.provides: source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.requires
	$(MAKE) -f source/kernel/CMakeFiles/kernel.dir/build.make source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.provides.build
.PHONY : source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.provides

source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.provides.build: source/kernel/CMakeFiles/kernel.dir/core/task.c.obj


# Object files for target kernel
kernel_OBJECTS = \
"CMakeFiles/kernel.dir/init/start.S.obj" \
"CMakeFiles/kernel.dir/cpu/cpu.c.obj" \
"CMakeFiles/kernel.dir/cpu/irq.c.obj" \
"CMakeFiles/kernel.dir/init/init.c.obj" \
"CMakeFiles/kernel.dir/dev/time.c.obj" \
"CMakeFiles/kernel.dir/dev/console.c.obj" \
"CMakeFiles/kernel.dir/ipc/mutex.c.obj" \
"CMakeFiles/kernel.dir/ipc/sem.c.obj" \
"CMakeFiles/kernel.dir/tools/log.c.obj" \
"CMakeFiles/kernel.dir/tools/bitmap.c.obj" \
"CMakeFiles/kernel.dir/tools/klib.c.obj" \
"CMakeFiles/kernel.dir/tools/list.c.obj" \
"CMakeFiles/kernel.dir/core/task.c.obj"

# External object files for target kernel
kernel_EXTERNAL_OBJECTS =

source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/init/start.S.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/init/init.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/core/task.c.obj
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/build.make
source/kernel/kernel: source/kernel/CMakeFiles/kernel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking C executable kernel"
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kernel.dir/link.txt --verbose=$(VERBOSE)
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && objcopy -S kernel.elf /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/../../image/kernel.elf
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && objdump -x -d -S -m i386 /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel/kernel.elf > kernel_dis.txt
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && readelf -a /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel/kernel.elf > kernel_elf.txt

# Rule to build all files generated by this target.
source/kernel/CMakeFiles/kernel.dir/build: source/kernel/kernel

.PHONY : source/kernel/CMakeFiles/kernel.dir/build

source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/init/start.S.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/cpu/cpu.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/cpu/irq.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/init/init.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/dev/time.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/dev/console.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/ipc/mutex.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/ipc/sem.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/tools/log.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/tools/bitmap.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/tools/klib.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/tools/list.c.obj.requires
source/kernel/CMakeFiles/kernel.dir/requires: source/kernel/CMakeFiles/kernel.dir/core/task.c.obj.requires

.PHONY : source/kernel/CMakeFiles/kernel.dir/requires

source/kernel/CMakeFiles/kernel.dir/clean:
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel && $(CMAKE_COMMAND) -P CMakeFiles/kernel.dir/cmake_clean.cmake
.PHONY : source/kernel/CMakeFiles/kernel.dir/clean

source/kernel/CMakeFiles/kernel.dir/depend:
	cd /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/source/kernel /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel /home/ziya/huangtan/lab/os/os_leenux/diy-x86os/code/huangtan/build/source/kernel/CMakeFiles/kernel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/kernel/CMakeFiles/kernel.dir/depend

