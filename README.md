Why another library to parse ISO 8583 messages?
---
I'm disappointed at the current libre C/Ruby implementations, they lack a clean
and robust interface.

The goal is to make bindings for several other programming languages, for now
I'm planing on.

    1. Ruby
    2. JavaScript
    3. Python (depends on the project's success)

Concept
---
![alt tag](http://i.imgur.com/H6aQqPn.png)

### Sample spec file
```ini
[bitmap]
size=64bit
type=hexadecimal

[mti]
number=200
name="text"
type=N
format=LLVAR
codec=BCD

# Yes, this is a comment

[3]
name="text"
format=LLLVAR
codec=ASCII
length=4
minimum=100
```
