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
### roadmap
- ~~Create a proper structure for the project.~~
- ~~Design the spec file~~
- ~~Implement the spec loader.~~
    1. ~~Implement tests.~~
- ~~Design and implement building process.~~
- ~~Simplify building process.~~
- ~~Decide whether this lib will support 128bit bitmaps.~~ (NO)
- Implement fields.
- Implement the Message Parser.
    2. Implement tests for Message Parser. (fields will be covered here)
- Implement the Message Builder.
    1. Implement tests for Message Builder.
    2. Implement tests to parse self-created messages.
- Optimization
- Micro-optimization
- Review portability issues (if any)

![alt tag](http://i.imgur.com/1no6Xm4.png)

### Sample spec file
```ini
[bitmap]
size=64bit
type=hexadecimal

[mti]
type=N
format=LLVAR
codec=BCD

# Yes, this is a comment

[3]
type=ANS
format=LLLVAR
codec=ASCII
```
