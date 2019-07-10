# Code Style
Contributions to libhorizon must adhere to the following guidelines.

## Types & enums
Use `UpperCamelCase` for types, enums, and enum-values.

## Functions
Use `camelCase` for function and method names.

### Getter & setter
 * For getter, use this syntax: `getMemberName`.
 * For setter, use this syntax: `setMemberName`.

#### Boolean getter & setter
Getter & setter that modify or read boolean members are edge-cases in the way they are called.

In order to make reading code easier, stick to the following naming conventions:

**If a boolean member enables/disables a feature:** Call the corresponding getter `isFeatureEnabled` and the setter `enableFeature` (Example: `isVideoRecordingEnabled`, `enableVideoRecording`).

**If a boolean member allows/forbids a certain action:** Call the corresponding getter `isActionAllowed` and the setter `allowFeature` (Example: `isHomeButtonAllowed`, `allowHomeButton`).

**If a getter checks whether a specific value is true or false:** Call it `isValue` (Example: `isHandheld`).

### Parameters
 * Use `camelCase` for function arguments and method parameters.
 * Use `const type&` if possible, when accepting objects as parameters (anything that's not a built-in type or a direct typedef based on a built-in type qualifies as an object).
 * Try to stay away from pointers in function arguments and method parameters.
 * Sort parameters in order of priority.
 * Give parameters that are the same value in most cases a default value.

## Private member variables
Use `m_thisFormat` for **private** member variables.
**Note:** For struct members and public/protected members, use `camelCase` without a prefix instead.

## Pointer and references
 * When declaring a pointer or reference, always have the asterisk or ampersand at the **end** of the _type_:
 ```cpp
    int* address;
    T& reference;
    const int* constAddress;
    const T& constRerence;
 ```
 * When declaring a multiple pointers or references, always have the asterisk or ampersand at the **beginning** of the _name_:
 ```cpp
    int *addr1,
        *addr2;
    T   &ref1,
        &ref2;
 ```

Try to stay away from macros. If you do use them, though, capitalize them `LIKE_THIS`.

## Files
 * Use include-guards as well as `#pragma once` in every file. Include guards should always follow the pattern `FILENAME_HPP`.
  * If a specific file using that include-guard already exists, use `MODULE_FILENAME_HPP` (Example: `CORE_MYFILE_HPP`, `AUDIO_MYFILE_HPP`).
 * Put a blank line before `#pragma once` and before your includes.
 * Put system-includes first and project includes second.
  * Keep the number of includes in your header files at a minimum. Forward-declare as much as possible and then only include those headers in your source file.
 * When using namespaces, put a comment after the closing-bracket containing only it's name.

Here is an example file:
```cpp
/**
 * @file file.hpp
 * @brief Your awesome file
 */
#ifndef FILE_HPP
#define FILE_HPP

#pragma once

#include <iostream>
#include "myFile.hpp"

namespace horizon {
    // your stuff
} /* horizon */

#endif /* end of include guard: FILE_HPP */

```

## Casting
When casting, always use C++-style casts (`static_cast`, `dynamic_cast`, etc...) as opposed to C-style casts (`(type) variable`).
