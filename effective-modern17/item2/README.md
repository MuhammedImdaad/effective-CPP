# Item 2: `if constexpr` - Conditional compilation made easy

## Overview

`if constexpr` enables conditional compilation within templates based on compile-time constants, making template metaprogramming much more readable and maintainable.

## Key Points

1. **Syntax**: `if constexpr (condition)` where condition is a compile-time constant expression
2. **Template context**: Must be used within a template
3. **Discarded statements**: Code in the non-taken branch is not instantiated
4. **No ODR violations**: Helps avoid One Definition Rule violations in templates

## Benefits

- Replaces complex SFINAE (Substitution Failure Is Not An Error) patterns
- More readable than `std::enable_if`
- Eliminates need for `template specialization` in many cases
- Prevents instantiation of invalid code paths

## When to Use

- Template functions that need different behavior for different types
- Replacing SFINAE-based conditional compilation
- Type trait-based branching in templates
- Simplifying complex template metaprogramming

## Performance

- Zero runtime overhead - all decisions made at compile time
- Can `reduce binary size` by eliminating unused template instantiations
- Faster compilation compared to SFINAE alternatives