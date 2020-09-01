################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Complex.cpp \
../src/Overloading\ the\ Insertion\ Operator\ for\ Printing.cpp 

OBJS += \
./src/Complex.o \
./src/Overloading\ the\ Insertion\ Operator\ for\ Printing.o 

CPP_DEPS += \
./src/Complex.d \
./src/Overloading\ the\ Insertion\ Operator\ for\ Printing.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Overloading\ the\ Insertion\ Operator\ for\ Printing.o: ../src/Overloading\ the\ Insertion\ Operator\ for\ Printing.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Overloading the Insertion Operator for Printing.d" -MT"src/Overloading\ the\ Insertion\ Operator\ for\ Printing.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


