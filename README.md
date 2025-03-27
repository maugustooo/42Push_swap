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

What is the target?The target number of every number in stack B is the smallest bigger number in stack A, and the number will stay above is respective target in stack A, for example in stack A we have(2 5 6) and in stack B(3), i need to put the number 3 above the number 5(is target), and will be (2 3 5 6).


After i set the target, i will set the price.
So, the price is basically the number of operations that will be needed to push the number from stack B to its respective target in stack A, and the formula to calculate the price is(price = if the number in stack B is above the half(position of the number) if not (length of stack B - position of the number) + if the target in stack A is above the half(position of the target) if not (length of stack A - position of the target).

The prices are set. Now, I will identify the cheapest. In push_swap, we need to sort with a limited number of operations, so I'm setting the prices and finding the cheapest to sort with the fewest operations possible. I'll search for the number with the lowest price to push from stack B to stack A and designate it as the cheapest number.

So, everything that needs to be set is set. Now it's time to push the numbers. First, I'll find the cheapest number (the one I've set as the cheapest). After that, I'll verify: if the cheapest number is above the half and its target is also above, I will rotate both stacks at the same time. This way, I can perform 2 rotations with 1 operation. If both are below the half, I'll perform a reverse rotate on both at the same time. After these two checks, I ensure that the number and its target are at the top of their respective stacks. If not, I will rotate them until they are on top. When both are at the top of their stacks, I push the number to stack A. I then repeat this process: setting the values again, rotating the cheapest, and pushing, until stack B is empty.

With stack B now empty, I will find the smallest number in stack A and rotate it to the top if it's above the half, or reverse rotate it if it's below the half. For example, if the stack is (6 7 9 1 3 4 5), rotating the 1 to the top will result in (1 3 4 5 6 7 9).


Now the stack is sorted:) I hope this explanation helps you understand the algorithm.
