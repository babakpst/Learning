################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Mutable\ Lambdas.cpp 

OBJS += \
./src/Mutable\ Lambdas.o 

CPP_DEPS += \
./src/Mutable\ Lambdas.d 


# Each subdirectory must supply rules for building sources it contributes
src/Mutable\ Lambdas.o: ../src/Mutable\ Lambdas.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Mutable Lambdas.d" -MT"src/Mutable\ Lambdas.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


