################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/lValues\ and\ rValues.cpp 

OBJS += \
./src/lValues\ and\ rValues.o 

CPP_DEPS += \
./src/lValues\ and\ rValues.d 


# Each subdirectory must supply rules for building sources it contributes
src/lValues\ and\ rValues.o: ../src/lValues\ and\ rValues.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/lValues and rValues.d" -MT"src/lValues\ and\ rValues.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


