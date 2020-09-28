################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Custom\ Exceptions.cpp 

OBJS += \
./src/Custom\ Exceptions.o 

CPP_DEPS += \
./src/Custom\ Exceptions.d 


# Each subdirectory must supply rules for building sources it contributes
src/Custom\ Exceptions.o: ../src/Custom\ Exceptions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Custom Exceptions.d" -MT"src/Custom\ Exceptions.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


