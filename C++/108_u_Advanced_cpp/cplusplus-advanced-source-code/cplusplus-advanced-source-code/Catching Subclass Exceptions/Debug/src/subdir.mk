################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Catching\ Subclass\ Exceptions.cpp 

OBJS += \
./src/Catching\ Subclass\ Exceptions.o 

CPP_DEPS += \
./src/Catching\ Subclass\ Exceptions.d 


# Each subdirectory must supply rules for building sources it contributes
src/Catching\ Subclass\ Exceptions.o: ../src/Catching\ Subclass\ Exceptions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Catching Subclass Exceptions.d" -MT"src/Catching\ Subclass\ Exceptions.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


