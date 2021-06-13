# Specify the minimum cmake version required for the project
cmake_minimum_required(VERSION 3.16)

# This will set PROJECT_NAME variable to CMAKE-TUTORAL
set(PROJECT_NAME CMAKE-TUTORIAL)

# Setting the project name, this should be done in the root CMakeLists.txt or else CMake behaves weird
# The weird syntax ${} is used to dereference a variable. It is recommended to always used quotes "" when dereferencing a variable
# as the variable might contain spaces which can cause issues when dereferencing the variable. Wrapping variable deferencing in quotes
# Makes the procedure safer
project("${PROJECT_NAME}" VERSION 1.0.3)

# Everything in CMake is a string, and all the arguments to CMake functions are space separated
# Hence, in a case we need to use a string having spaces, it should be wrapped in quotes ""
# messae() prints a message when running cmake
message(STATUS "This is a random message")

# Regular if conditional statement like in every known programming language
if("FALSE") # Takes aregument, currently always evaluates to true becuase of the argument
	message(STATUS "Message printed from the if() statement body")
else() # Doesn't take any arguments
	message(STATUS "Message printed from the else() statement body")
endif()

# We can also pass variables as arguments to the if() statment, duh!
set(CONDITION TRUE)
if(NOT "${CONDITION}") # You can also use NOT keyword to negate the condition
	message(STATUS "Variable evaluted to TRUE")
else() # Doesn't take any arguments
	message(STATUS "Variable evalutated to FALSE")
endif()

# We can also use strings and string comparisions to evalute if() condition
set(STRING_1 "This is string 1")
set(STRING_2 "This is string 2")
if("${STRING_1}" STREQUAL "${STRING_2}") # Checking if string-1 is equal to string-2 or not
	message(STATUS "STRING_1 and STRING_2 are same")
elseif(NOT STRING_1 STREQUAL "STRING_2") # elseif() takes argument, this is also an example of auto deferencing.
# STRING_1 is trated as variable and deferenced with its value whereas STRING_2 is taken as string literal because it is inside quotes and without the
# ${} deference.
	message(STATUS "elseif() condition evaluated to TRUE")
else() # Doesn't take any arguments
	message(STATUS "STRING_1 and STRING_2 are not same")
endif()

# We can also use loops having same arguments as if()
# while loop
set(loop_itr 4)
while(loop_itr LESS 10)
	message(STATUS "Inside loop body. Value is ${loop_itr}")
	math(EXPR loop_itr "${loop_itr} + 1") # Incrementing the value of loop_itr variable by 1 in each iteration
endwhile()

# foreach loop
foreach(item IN ITEMS foo bar baz quz)
	message(STATUS "Item is: ${item}")
endforeach()

# foreach loop
foreach(loop_itr RANGE 0 100 20) # Can also use range, similar to Python range()
	message(STATUS "Loop itr value is: ${loop_itr}")
endforeach()