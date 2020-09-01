################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Writing\ Text\ Files.cpp 

OBJS += \
./src/Writing\ Text\ Files.o 

CPP_DEPS += \
./src/Writing\ Text\ Files.d 


# Each subdirectory must supply rules for building sources it contributes
src/Writing\ Text\ Files.o: ../src/Writing\ Text\ Files.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Writing Text Files.d" -MT"src/Writing\ Text\ Files.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


