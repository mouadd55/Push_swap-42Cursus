<div align=center >
<h1>Push_swap</h1>
</div>
<p align="center">
    <img src="https://user-images.githubusercontent.com/81205527/191116700-f59a18fd-e7f5-4c76-8f41-74a68d1ba32b.png">
</p>
<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/surfi89/get_next_line?color=blue" />
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

---

## 💡 About the project

> _This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting._

For more detailed information, look at the [**subject of this project**](https://github.com/mouadd55/Push_swap-42Cursus/blob/62df8f9be4a4bbba68bb7b1978234b6b11bedf15/push_swap.pdf).
<br><br><br>

## Overview
The Push_Swap project is an algorithmic challenge that aims to sort a stack of integers using a limited set of instructions in the most efficient way possible.
- The limited set of instructions are:

| Operation | Description |
| ------------ | ------------ |
| `sa` | swap A - swap the first 2 elements at the top of stack A |
| `sb` | swap B - swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | push A - take the first element at the top of b and put it at the top of A |
| `pb` | push B - take the first element at the top of a and put it at the top of B |
| `ra` | rotate A - shift up all elements of stack A by 1. The first element becomes the last one |
| `rb` | rotate B - shift up all elements of stack B by 1. The first element becomes the last one |
| `rr` | `ra` and `rb` at the same time |
| `rra` | reverse rotate A - shift down all elements of stack A by 1. The last element becomes the first one |
| `rrb` | reverse rotate B - shift down all elements of stack B by 1. The last element becomes the first one |
| `rrr` | `rra` and `rrb` at the same time |

## Objectives
- Understand and implement sorting algorithms.
- Learn about algorithmic complexity.
- Rigorous use of C programming language.

## Common Instructions
- Written in C.
- No memory leaks allowed.
- Makefile with specific rules is required.
- Error handling is essential.

## Installation
```bash
git clone <repository_url>
cd push_swap
make

Then run it with :

```shell
./push_swap <numbers>
```

The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

```shell
./push_swap 9 0 -217 2147483647 -2147483648
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

![Push_swap](https://drive.google.com/file/d/1G76xKcXso4aK0TuDXaSFT3LFfLrSL2ts/view?usp=sharing)
