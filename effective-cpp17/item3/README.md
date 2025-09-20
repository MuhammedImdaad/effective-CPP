# Item 3: `std::optional` - Express optional values explicitly

## Overview

`std::optional<T>` is a vocabulary type that represents a value that may or may not be present, providing a type-safe alternative to null pointers and sentinel values.

## Key Points

1. **Type-safe nullability**: Explicitly indicates when a value might be absent
2. **No dynamic allocation**: Stack-based storage
3. **Value semantics**: Copy/move constructible like regular values
4. **Explicit checks**: Forces explicit handling of the "no value" case

## Benefits

- Eliminates undefined behavior from null pointer dereference
- Self-documenting APIs - return type shows optionality
- Replaces error-prone patterns like returning `-1` or `nullptr`
- Integrates well with modern C++ idioms

## When to Use

- Functions that may fail to return a value
- Optional parameters in APIs
- Replacing nullable pointers for value types
- `Configuration settings that may be unset`
- Parsing operations that may fail

## Performance

- Minimal overhead - typically just one extra byte for the flag
- No heap allocation
- Copy/move operations are efficient
- Zero-cost when not used