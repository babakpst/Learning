################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bitmap.cpp \
../src/FractalCreator.cpp \
../src/Mandelbrot.cpp \
../src/ZoomList.cpp \
../src/main.cpp 

OBJS += \
./src/Bitmap.o \
./src/FractalCreator.o \
./src/Mandelbrot.o \
./src/ZoomList.o \
./src/main.o 

CPP_DEPS += \
./src/Bitmap.d \
./src/FractalCreator.d \
./src/Mandelbrot.d \
./src/ZoomList.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


