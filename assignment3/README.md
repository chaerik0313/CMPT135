# Assignment 3: Formatted Lists

Your task is to implement and test a number of different classes for making
nicely formatted lists.

## Getting Started

For this assignment, put all the code you write into [a3.cpp](a3.cpp). 

Among other files, [a3.cpp](a3.cpp) #includes [List_base.h](List_base.h),
which has the `List_base` base class your classes must inherit from. All the
methods in [List_base.h](List_base.h) are virtual, and many are abstract. Your
inheriting classes should implement all the abstract methods in a sensible way
that fits the description and examples given for each. We want to see you use
good programming style and make use of C++'s object-oriented features.

**Important**: For each class you write, implement a default constructor
that creates an empty list.

Make sure to test all your methods!


## The List_base Class

`List_base`, which is in the file [List_base.h](List_base.h) is a base class
that `Bulleted_list` and `Numbered_list` should both inherit from. Both
`Bulleted_list` and `Numbered_list` should implement all the abstract methods
they inherit from [List_base.h](List_base.h) in a correct way that makes sense
for them.

The comments in [List_base.h](List_base.h) describe how the methods should
work.


## Bulleted Lists

The `Bulleted_list` class represents bulleted lists. A bullet list is
displayed as a sequence of strings, one string per line, each line beginning
with the same *bullet string*. The default bullet string is "- ".

For example:

```cpp
Bulleted_list lst;

lst.add_to_end("oranges");
lst.add_to_end("pears");
lst.add_to_end("grapes");
lst.add_to_start("apples");

cout << lst.to_str();
```

This prints:

```
- apples
- oranges
- pears
- grapes
```

You can change the number of spaces that each line begins with using
`set_indent`:

```
lst.set_indent(3);
cout << "\n";
cout << lst.to_str();
```

This prints:

```
   - apples
   - oranges
   - pears
   - grapes
```

The indent string is `"   "` (three spaces), which is what `get_indent()`
returns.

You can change the bullet string with the setter `set_bullet`:

```
lst.set_indent(0);
lst.set_bullet("** ");
cout << "\n";
cout << lst.to_str();
```

This prints:

```
** apples
** oranges
** pears
** grapes
```

`Bulleted_list` also has a `const` getter called `get_bullet()` that returns
the current bullet string. Both `set_bullet` and `get_bullet` are specific to
`Bulleted_list`.

The `reverse_order` method reverse the order of the lines:

```
lst.set_bullet("- ");
lst.reverse_order();
cout << "\n";
cout << lst.to_str();
```

This prints:

```
- grapes
- pears
- oranges
- apples
```

The `to_html_str()` method returns a string that will be displayed as an
unordered list when viewed in a web browser:

```cpp
lst.reverse_order();
cout << "\n";
cout << lst.to_html_str();
```

This prints:

```
<ul>
  <li>apples</li>
  <li>oranges</li>
  <li>pears</li>
  <li>grapes</li>
</ul>
```

This is an HTML **unordered list**: it starts with `<ul>`, ends with `</ul>`,
and in between every list item starts with `<li>` and ends with `</li>`. For
HTML lists, the indent string is ignored.

The code, and output, for the code used here is in the function `demo1()` at
the bottom of [a3.cpp](a3.cpp).


## Numbered Lists

The `Numbered_list` class represents numbered lists. A number list is
displayed as a sequence of strings, one string per line, each line beginning
with a number in sequence. The default first number is 1.

For example:

```cpp
Numbered_list lst;

lst.add_to_end("oranges");
lst.add_to_end("pears");
lst.add_to_end("grapes");
lst.add_to_start("apples");

cout << lst.to_str();
```

This prints:

```
1. apples
2. oranges
3. pears
4. grapes
```

You can change the string between the number and the string using the
`set_num_sep` setter:

```cpp
lst.set_num_sep(") ");
cout << "\n";
cout << lst.to_str();
```

This prints:

```
1) apples
2) oranges
3) pears
4) grapes
```

There's also the getter `get_num_sep()` that returns the current number
separation string. Both `set_num_sep` and `get_num_sep` are specific to
`Numbered_list`.

You can set and get the *first* number of a list using `set_start_num` and
`get_start_num`:

```cpp
lst.set_start_num(3);
cout << "\n";
cout << lst.to_str();
```

```
3) apples
4) oranges
5) pears
6) grapes
```

Both `set_start_num` and `get_start_num` are specific to the `Numbered_list`
class. If `set_start_num` is passed a *negative* number, then it is
automatically set to 0 ( so the lowest possible start value is 0).

Reversing a numbered list reverses the elements of the list and also the
numbers:

```cpp
lst.set_start_num(1);
lst.reverse_order();
cout << "\n";
cout << lst.to_str();
```

This prints:

```
4) grapes
3) pears
2) oranges
1) apples
```

The starting number should always be the number of the last item in a reversed
list:

```cpp
lst.set_start_num(3);
cout << "\n";
cout << lst.to_str();
```

```
6) grapes
5) pears
4) oranges
3) apples
```

The `to_html_str()` method returns an HTML string version of the list:

```cpp
lst.reverse_order();
cout << "\n";
cout << lst.to_html_str();
```

This prints:

```
<ol>
  <li>apples</li>
  <li>oranges</li>
  <li>pears</li>
  <li>grapes</li>
</ol>
```

This is an *ordered HTML list*. It begins with the tag `<ol>`, ends with the
tag `</ol>`, and each line of the list is sandwiched between `<li>` and
`</li>`.

A reversed HTML list reverses both the strings and the numbers. To reverse the
numbers in an HTML list, replace `<ol>` with `<ol reversed>`:

```cpp
lst.reverse_order();
cout << "\n";
cout << lst.to_html_str();
```

This prints:

```
<ol reversed>
  <li>grapes</li>
  <li>pears</li>
  <li>oranges</li>
  <li>apples</li>
</ol>
```

The indentation string and the number separator are ignored by
`to_html_str()`.

The code, and output, for the code used here is in the function `demo2()` at
the bottom of [a3.cpp](a3.cpp).


## Submit Your Work

Please put all your code into [a3.cpp](a3.cpp), and submit it on Canvas.
Implement **all** the abstract methods that appear in
[List_base.h](List_base.h), along with any class-specific methods described in
the sections above. Use exactly the names and types given in the assignment,
otherwise the marking software will probably give you 0!

You can write write helper methods and functions if necessary.

The only file you submit is [a3.cpp](a3.cpp): *don't* submit any other files.
The marker will use the standard [makefile](makefile) to compile it, and a
copy of [cmpt_error.h](cmpt_error.h) and [List_base.h](List_base.h) will be in
the same folder as [a3.cpp](a3.cpp) when it's tested.


## Basic Requirements

Before we give your program any marks, it must meet the following basic
requirements:

- It must compile on Ubuntu Linux using the standard course
  [makefile](makefile):
  
  ```
  $ make a3
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   a3.cpp   -o a3
  ```
  
  If your program fails to compile, your mark for this assignment will be 0.

  A copy of [cmpt_error.h](cmpt_error.h) will be in the same folder as
  [a3.cpp](a3.cpp) when it's compiled, so your program can use `cmpt::error`
  if necessary.

- It must have no memory leaks or memory errors, according to `valgrind`,
  e.g.:

  ```
  $ valgrind ./a3
    
  // ... lots of output ... 
  ```

  A program is considered to have no memory error if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
    lost` must all be 0.

  - The `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non- zero number of
    bytes.

- **You must include the large comment section with student info and the
  statement of originality**. If your submitted file does not have this, then
  we will assume your work is not original and it will not be marked.
  
If your program meets all these basic requirements, then it will graded using
the marking scheme on Canvas.


## Marking Scheme

### Source Code Readability (6 marks)

- All names of variables, functions, structs, classes, etc. are sensible,
  self-descriptive, and consistent.

- Indentation and spacing is perfectly consistent and matches the structure of
  the program. All blank lines and indents should have a reason.

- All lines are 100 characters in length, or less.

- Comments are used when appropriate, e.g to describe code that is tricky or
  very important. There are no unnecessary comments, and no commented-out
  code.

- Appropriate features of C++ are used in an appropriate way. For example, do
  **not** use a feature of C (like C-style strings) when there is a better C++
  feature (e.g. the standard `string` class). Don't use any features you don't
  understand.

- Overall, the source code is easy to read and understand.


### Bulleted list Class (12 marks)

**7 marks**: 1 mark for each correct and sensible implementation of an
*abstract* method inherited from `List_base`.

**1 mark** A correct and sensible default constructor.

**2 marks** The setter `set_bullet` and getter `get_bullet` are implemented
correctly and sensibly.

**2 marks** Reasonable and automated test functions have been written for the
`to_str()` and `to_html_str()` methods.


### Numbered list Class (16 marks)

**7 marks**: 1 mark for each correct and sensible implementation of an
*abstract* method inherited from `List_base`.

**1 mark** A correct and sensible default constructor.

**2 marks** The setter `set_start_num` and getter `get_start_num` are
implemented correctly and sensibly.

**2 marks** The setter `set_num_sep` and getter `get_num_sep` are implemented
correctly and sensibly.

**1 mark** Lists are correctly reversed, i.e. both the numbers and list items
have their order reversed.

**1 mark** `to_html_str()` returns a string that uses the HTML `reversed`
attribute to correctly print the list items and numbers in reverse order.

**2 marks** Reasonable and automated test functions have been written for the
`to_str()` and `to_html_str()` methods.
