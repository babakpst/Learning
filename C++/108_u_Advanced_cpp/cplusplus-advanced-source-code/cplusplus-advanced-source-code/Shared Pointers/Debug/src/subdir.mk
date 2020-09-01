################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Shared\ Pointers.cpp 

OBJS += \
./src/Shared\ Pointers.o 

CPP_DEPS += \
./src/Shared\ Pointers.d 


# Each subdirectory must supply rules for building sources it contributes
src/Shared\ Pointers.o: ../src/Shared\ Pointers.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Shared Pointers.d" -MT"src/Shared\ Pointers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


