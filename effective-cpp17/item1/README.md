# Item 1: Structured Bindings - Decompose objects elegantly

## Overview

Structured bindings allow you to decompose objects (tuples, pairs, arrays, structs) into individual variables in a single declaration.

## Key Points

1. **Syntax**: `auto [var1, var2, ...] = expression;`
2. **Works with**: tuples, pairs, arrays, and structs/classes with public data members
3. **Reference binding**: Use `auto&` or `const auto&` for references
4. **Type deduction**: The compiler deduces types automatically

## When to Use

- Functions returning multiple values (via tuple/pair)
- Iterating over maps or containers of pairs
- Working with structured data
- Any time you need to "unpack" an object

## Performance

- Zero runtime overhead - it's purely a language feature
- Reference binding avoids unnecessary copies
- Suprisingly have a negative impact on `RVO`, when you create a local variable through the feature and return it, `RVO` won't be applied to the object being returned. Hence for performance, you might need to consider casting it via std::move (might have been fixed in future versions)

### THINGS TO REMEMBER
* syntax: auto [ ... ] = ...
