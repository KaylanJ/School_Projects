# CS Assignments – README

A collection of C programming assignments covering string manipulation, CSV data querying, and recursive algorithms.

---

## Assignment 4 – String Utility Library

A custom string utility library built without using standard library string functions.

### Files

| File | Description |
|---|---|
| `fns.c` | Implementation of all string utility functions |
| `main.c` | Driver program with test cases for each function |
| `Makefile` | Build configuration |

### Functions

**`int strLen(char *s)`**
Returns the length of a string by walking it until the null terminator. Equivalent to `strlen`.

**`char *upper(char *msg)`**
Returns a newly heap-allocated string with all lowercase letters converted to uppercase. The caller is responsible for freeing the result.

**`char *lower(char *msg)`**
Returns a newly heap-allocated string with all uppercase letters converted to lowercase. The caller is responsible for freeing the result.

**`int vowels(char *msg)`**
Counts the number of vowels (a, e, i, o, u, y) in a string, case-insensitive. Returns `-1` on allocation failure.

**`int countChar(char *msg, char search)`**
Counts how many times a specific character appears in a string.

**`char *substringMatch(char *msg, char *submsg)`**
Searches for `submsg` within `msg`. Returns a pointer to the first match location in `msg`, or `NULL` if not found.

**`char *delimit(char *msg, char delim)`**
Copies characters from `msg` into a new heap-allocated string, stopping at the first occurrence of `delim` or the null terminator. The caller is responsible for freeing the result.

**`char *substringDelete(char *msg, char *submsg)`**
Returns a new heap-allocated copy of `msg` with all occurrences of `submsg` removed. The caller is responsible for freeing the result.

**`int flow(char *msg)`**
Checks whether a string has "flow" — that is, whether the last letter before each space matches the first letter after it (case-insensitive). Returns `1` for flow, `0` for no flow, `-1` on error.

### Building and Running

```bash
make
./prog
```

### Notes

- Functions that return `char *` allocate memory with `malloc`. Always `free()` the result when done.
- `NULL` return values indicate a memory allocation failure.
- `substringMatch` returns a pointer *into* the original string — do not free it.

---

## Assignment 7 – CSV Query Processor

A command-line tool that filters rows from a CSV data file based on structured query files.

### Files

| File | Description |
|---|---|
| `as7.c` | Query parsing and filtering logic |
| `main.c` | Entry point; reads query file and dispatches each query |
| `Makefile` | Build configuration |
| `queries.csv` | Example query file |

### How It Works

The program takes two command-line arguments: a data CSV file and a query file. Each line in the query file defines one query, and each query produces its own output file containing the matching rows.

### Query Format

Each query line is comma-delimited with five fields:

```
outputfile,regionList,ageList,charList,condition
```

| Field | Description |
|---|---|
| `outputfile` | Name of the file to write matching rows to |
| `regionList` | `$`-separated list of region values to match, or `N/A` to skip |
| `ageList` | Space-separated list of age values to match, or `N/A` to skip |
| `charList` | Space-separated list of characteristic values to match, or `N/A` to skip |
| `condition` | A numeric condition like `>1000`, `<500`, or `=10001` applied to a value column, or `N/A` to skip |

The special region value `Combined` will match any row whose region field contains the word "Combined".

### Example Queries (`queries.csv`)

| Output File | Region | Age | Char | Condition |
|---|---|---|---|---|
| `Test1.csv` | `Saint John$Fredericton` | `1 4 8` | `90 91 92` | `N/A` |
| `Test2.csv` | `Miramichi` | `N/A` | `N/A` | `N/A` |
| `Test3.csv` | `Dieppe$Fredericton` | `1 4 8` | `1` | `>1000` |
| `Test4.csv` | `Combined$Fredericton$Rothesay` | `1` | `1` | `50 N/A` |
| `Test5.csv` | `N/A` | `1 2 3 4 5` | `1 2 3 4 5` | `>10000` |
| `Test6.csv` | `N/A` | `N/A` | `N/A` | `=10001` |

### Building and Running

```bash
make
./prog data.csv queries.csv
```

### Notes

- All five query fields are required per line. Missing fields will produce an "Invalid query format" error and skip that query.
- Whitespace around region values is trimmed automatically.
- The program uses `getline` for dynamic line reading and closes all file handles on completion.
- It is missing the big census data file for CSV, however it uses the official census format.

---

## Assignment 8 – Recursive Algorithms

A set of recursive functions covering string searching, 2D array compression, and in-place sorting.

### Files

| File | Description |
|---|---|
| `as8.c` | Implementation of recursive functions |
| `main.c` | Driver program with test cases |
| `Makefile` | Build configuration |

### Functions

**`char *adjacentLetters(char *look)`**
Recursively searches a string for the first pair of adjacent characters that are consecutive letters of the alphabet (e.g. `m` followed by `n`, case-insensitive). Returns a pointer to the first character of the matching pair, or `NULL` if none is found.

**`int *compress2D(int **arr, int rows)`**
Takes a 2D array where each row has exactly 3 integers, and returns a new heap-allocated 1D array. For each row, the result is `(max * min) - middle`. The caller is responsible for freeing the result.

Internally delegates to `compress2DRec`, which processes one row per recursive call.

**`void insertionSortRec(int *arr, int size, int sortedCount, int mode)`**
Sorts an integer array in-place using recursive insertion sort.
- `mode = 0` — ascending order
- `mode = 1` — descending order

Initial call should pass `sortedCount = 1`.

### Building and Running

```bash
make
./prog
```

### Example Output

```
Found at: No          ← adjacentLetters("akMjNoE") finds 'N','o'
Found at: et          ← adjacentLetters("zZet") finds 'e','t'
55 43                 ← compress2D result for {{5,8,11},{4,1,12}}
Ascending:
1 2 3 5 8
Descending:
8 5 3 2 1
```

### Notes

- `compress2D` allocates memory with `malloc`. Always `free()` the result when done.
- `adjacentLetters` returns a pointer into the original string — do not free it.
- `insertionSortRec` sorts in-place; no allocation or freeing needed.

---
