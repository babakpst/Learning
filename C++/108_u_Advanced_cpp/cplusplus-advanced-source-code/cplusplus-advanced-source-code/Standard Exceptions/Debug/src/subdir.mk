################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Standard\ Exceptions.cpp 

OBJS += \
./src/Standard\ Exceptions.o 

CPP_DEPS += \
./src/Standard\ Exceptions.d 


# Each subdirectory must supply rules for building sources it contributes
src/Standard\ Exceptions.o: ../src/Standard\ Exceptions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Standard Exceptions.d" -MT"src/Standard\ Exceptions.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


