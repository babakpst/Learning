################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Delegating\ Conctructors.cpp 

OBJS += \
./src/Delegating\ Conctructors.o 

CPP_DEPS += \
./src/Delegating\ Conctructors.d 


# Each subdirectory must supply rules for building sources it contributes
src/Delegating\ Conctructors.o: ../src/Delegating\ Conctructors.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Delegating Conctructors.d" -MT"src/Delegating\ Conctructors.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


