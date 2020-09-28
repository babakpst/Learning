################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Reinterpret\ Cast.cpp 

OBJS += \
./src/Reinterpret\ Cast.o 

CPP_DEPS += \
./src/Reinterpret\ Cast.d 


# Each subdirectory must supply rules for building sources it contributes
src/Reinterpret\ Cast.o: ../src/Reinterpret\ Cast.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Reinterpret Cast.d" -MT"src/Reinterpret\ Cast.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


