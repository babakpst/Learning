################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Static\ Cast.cpp 

OBJS += \
./src/Static\ Cast.o 

CPP_DEPS += \
./src/Static\ Cast.d 


# Each subdirectory must supply rules for building sources it contributes
src/Static\ Cast.o: ../src/Static\ Cast.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Static Cast.d" -MT"src/Static\ Cast.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


