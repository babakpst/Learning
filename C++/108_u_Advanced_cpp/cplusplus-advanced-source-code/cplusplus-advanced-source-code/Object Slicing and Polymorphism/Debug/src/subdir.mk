################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Object\ Slicing\ and\ Polymorphism.cpp 

OBJS += \
./src/Object\ Slicing\ and\ Polymorphism.o 

CPP_DEPS += \
./src/Object\ Slicing\ and\ Polymorphism.d 


# Each subdirectory must supply rules for building sources it contributes
src/Object\ Slicing\ and\ Polymorphism.o: ../src/Object\ Slicing\ and\ Polymorphism.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Object Slicing and Polymorphism.d" -MT"src/Object\ Slicing\ and\ Polymorphism.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


