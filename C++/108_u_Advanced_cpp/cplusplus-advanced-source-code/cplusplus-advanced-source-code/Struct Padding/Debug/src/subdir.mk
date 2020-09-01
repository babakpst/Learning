################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Binary\ Files.cpp 

OBJS += \
./src/Binary\ Files.o 

CPP_DEPS += \
./src/Binary\ Files.d 


# Each subdirectory must supply rules for building sources it contributes
src/Binary\ Files.o: ../src/Binary\ Files.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Binary Files.d" -MT"src/Binary\ Files.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


