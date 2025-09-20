# Item 6: `std::variant` - Type-safe unions

## Overview

`std::variant` is a type-safe union that can hold a value of one of several specified types at any given time. It provides a modern, safe alternative to C-style unions with `automatic type tracking` and exception safety.

## Key Points

1. **Type safety**: Knows which type it currently holds
2. **Exception safety**: Strong exception safety guarantees
3. **No undefined behavior**: Unlike C unions
4. **Comparison with any**: Almost always better than std::any due to static storage and type safety

## Benefits

- Eliminates undefined behavior from C unions
- Compile-time type checking
- Automatic memory management
- Rich API for type queries and access
- Integrates well with modern C++ idioms

## When to Use

- Representing values that can be one of several types
- State machines with different state data
- Parsing results (success value or error)
- Configuration options with different types
- Replacing error-prone void* patterns

## Performance

- Minimal overhead - typically size of largest type + discriminator (4 bytes)
- No heap allocation