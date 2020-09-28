################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Reading\ and\ Writing\ Binary\ Files.cpp 

OBJS += \
./src/Reading\ and\ Writing\ Binary\ Files.o 

CPP_DEPS += \
./src/Reading\ and\ Writing\ Binary\ Files.d 


# Each subdirectory must supply rules for building sources it contributes
src/Reading\ and\ Writing\ Binary\ Files.o: ../src/Reading\ and\ Writing\ Binary\ Files.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Reading and Writing Binary Files.d" -MT"src/Reading\ and\ Writing\ Binary\ Files.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


