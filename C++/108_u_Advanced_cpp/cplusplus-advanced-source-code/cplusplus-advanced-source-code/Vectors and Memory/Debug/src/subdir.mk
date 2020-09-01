################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Vectors\ and\ Memory.cpp 

OBJS += \
./src/Vectors\ and\ Memory.o 

CPP_DEPS += \
./src/Vectors\ and\ Memory.d 


# Each subdirectory must supply rules for building sources it contributes
src/Vectors\ and\ Memory.o: ../src/Vectors\ and\ Memory.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Vectors and Memory.d" -MT"src/Vectors\ and\ Memory.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


