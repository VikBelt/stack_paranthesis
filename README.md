# stack_paranthesis
A program to check if parenthesis are balanced in a string - based on a Stack ADT. The stack capacity will double when it becomes full - this prevents overflow. 
## stack function documentation - stack.h
This is my implementation of a Stack  ADT which lives on the heap. 
### public member functions
push - adds an element to the top of the stack
pop - removes an element from the stack
peak - returns the top element of the stack
empty - checks if the stack is empty
print - prints contents of the stack
clear - resets the stack
size - returns the size of the stack
to_vector - converts the stack to an std::vector
capacity - returns the capacity of the stack 
