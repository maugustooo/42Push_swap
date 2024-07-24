<div align="Center">
	<h1>42 Push_Swap</h1>
<h3>Because swap_push isn't as natural<br><br><br>
</h3>
</div>

> [!IMPORTANT]  
> This is just a visualizer to see my algorithm working
![Screencast from 07-23-2024 03-52-28 PM](https://github.com/user-attachments/assets/f684590c-5e65-4f76-ac0d-fa346cc67097)
> ><p><a href="https://github.com/o-reo/push_swap_visualizer">The owner of the visualizer</a></p>

## Introduction

This project comprises an interesting case study regarding sorting algorithms and its performances, being part of the core curriculum of all 42 schools worldwide. The task is simple: given a sequence of random numbers disposed in a stack data structure (**stack A**), sort them with the help of an empty auxiliary stack (**stack B**) and a set of specific stack operations. The operations allowed are described as follows, as written in our task:

- **`sa`** : **swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements).
- **`sb`** : **swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements).
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- **`ra`** : **rotate a** - shift up all elements of stack A by 1. The first element becomes the last one.
- **`rb`** : **rotate b** - shift up all elements of stack B by 1. The first element becomes the last one.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - shift down all elements of stack A by 1. The last element becomes the first one.
- **`rrb`** : **reverse rotate b** - shift down all elements of stack B by 1. The last element becomes the first one.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

## Algorithm 

First i push every number from stack A to stack B, until 3 numbers are left in stack A, after that i sort the 3 numbers in stack A.
Now i will set the positions of the number in stack A and stack B, the positions is where the numbers are in stack, for example(1 2 3) position of 1(the first number) is 0, position of number 2 is 1, etc..., i also set if they are bove or below the half, for example (1 2 3 4), 1 and 2 are above, 3 and 4 are below, and i set the target of every number in stack B.
