################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Template\ Functions\ and\ Type\ Inference.cpp 

OBJS += \
./src/Template\ Functions\ and\ Type\ Inference.o 

CPP_DEPS += \
./src/Template\ Functions\ and\ Type\ Inference.d 


# Each subdirectory must supply rules for building sources it contributes
src/Template\ Functions\ and\ Type\ Inference.o: ../src/Template\ Functions\ and\ Type\ Inference.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Template Functions and Type Inference.d" -MT"src/Template\ Functions\ and\ Type\ Inference.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


