################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Rvalue\ References.cpp 

OBJS += \
./src/Rvalue\ References.o 

CPP_DEPS += \
./src/Rvalue\ References.d 


# Each subdirectory must supply rules for building sources it contributes
src/Rvalue\ References.o: ../src/Rvalue\ References.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Rvalue References.d" -MT"src/Rvalue\ References.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


