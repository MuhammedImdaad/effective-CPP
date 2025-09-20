# Item 4: `std::string_view` - Efficient string references

## Overview

`std::string_view` is a lightweight, non-owning reference to a sequence of characters. It provides a read-only view of string data without copying, making string operations more efficient.

## Key Points

1. **Non-owning**: Does not manage memory, just provides a view
2. **Lightweight**: Typically just a pointer and size
3. **Read-only**: Cannot modify the underlying string
4. **Universal**: Works with C strings, std::string, string literals, etc.

## Benefits

- Eliminates unnecessary string copies
- Uniform interface for different string types
- Reduces memory allocations
- Improves performance for temporary string operations

## When to Use

- Function parameters that don't need to own the string
- Parsing and tokenization operations
- String searching and comparison
- APIs that work with multiple string types

## Performance

- Constant time construction from any string type
- No memory allocation
- `Significantly faster` than passing std::string by value
- `Copy operations are trivial` (just copying pointer + size)

## `Cautions`

- **Dangling references**: Ensure the underlying string outlives the string_view
- **No null termination guarantee**: Unlike C strings
- **Modification through original**: Changes to original string affect the view
- **Mixed usage with string**: Do not move back and forth with strings, it might become less performative