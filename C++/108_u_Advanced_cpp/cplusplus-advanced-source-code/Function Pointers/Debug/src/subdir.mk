################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Function\ Pointers.cpp 

OBJS += \
./src/Function\ Pointers.o 

CPP_DEPS += \
./src/Function\ Pointers.d 


# Each subdirectory must supply rules for building sources it contributes
src/Function\ Pointers.o: ../src/Function\ Pointers.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Function Pointers.d" -MT"src/Function\ Pointers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


