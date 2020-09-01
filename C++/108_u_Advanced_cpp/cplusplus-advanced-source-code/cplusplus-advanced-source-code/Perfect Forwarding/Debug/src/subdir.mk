################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Perfect\ Forwarding.cpp 

OBJS += \
./src/Perfect\ Forwarding.o 

CPP_DEPS += \
./src/Perfect\ Forwarding.d 


# Each subdirectory must supply rules for building sources it contributes
src/Perfect\ Forwarding.o: ../src/Perfect\ Forwarding.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Perfect Forwarding.d" -MT"src/Perfect\ Forwarding.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


