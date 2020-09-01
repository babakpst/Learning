################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Dynamic\ Casts.cpp 

OBJS += \
./src/Dynamic\ Casts.o 

CPP_DEPS += \
./src/Dynamic\ Casts.d 


# Each subdirectory must supply rules for building sources it contributes
src/Dynamic\ Casts.o: ../src/Dynamic\ Casts.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Dynamic Casts.d" -MT"src/Dynamic\ Casts.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


