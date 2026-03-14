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

## JavaScript – Insurance Dashboard (Next.js)

A Next.js web application for managing insurance policies, users, and credit profiles. Built with TypeScript, PostgreSQL, and a component-based UI using a sidebar layout.

---

### Credit API

**File:** `app/api/credit/route.ts`

**`POST /api/credit`**

Looks up a customer by email and returns their credit profile along with a suggested premium adjustment multiplier.

**Request body:**
```json
{ "email": "customer@example.com" }
```

**Response:**
```json
{
  "success": true,
  "profile": {
    "name": "Jane Doe",
    "email": "customer@example.com",
    "credit_score": 720,
    "risk_level": "low",
    "last_checked": "2024-01-15T00:00:00Z",
    "suggested_multiplier": 0.95
  }
}
```

**Premium adjustment logic:**

| Risk Level | Multiplier | Effect |
|---|---|---|
| `low` | `0.95` | 5% discount |
| `medium` | `1.0` | No change |
| `high` | `1.15` | 15% surcharge |

**Error responses:** `400` if email is missing, `404` if user or credit profile not found, `500` on database error.

---

### Policies API

**File:** `app/api/policies/route.ts`

Handles creating, reading, and updating insurance policies. Uses a shared `pool` from `@/lib/db`.

**`GET /api/policies`**

Returns all policies joined with their associated user. Optionally filter by user with a query parameter.

```
GET /api/policies?userId=3
```

Each policy in the response includes a nested `user` object with `id`, `firstName`, `lastName`, and `email`.

**`POST /api/policies`**

Creates a new policy with status `under_review`. Auto-generates a policy number in the format `POL-YYYY-NNNN`.

**Required body fields:** `userId`, `type`, `coverageAmount`, `premium`, `startDate`, `endDate`

Returns `201` on success with the created policy. Returns `409` if a duplicate policy number collision occurs.

**`PATCH /api/policies?id=5`**

Updates the status of an existing policy by ID.

**Required body field:** `status`

---

### Users API

**File:** `app/api/users/route.ts`

**`GET /api/users`**

Returns all users with their full profile: credit score, risk level, all associated policies, and all associated claims. Performs per-user subqueries for policies and claims.

**Response shape per user:**
```json
{
  "id": 1,
  "firstName": "Jane",
  "lastName": "Doe",
  "email": "jane@example.com",
  "creditScore": 720,
  "riskLevel": "low",
  "policies": [...],
  "claims": [...]
}
```

---

### Policies Page

**File:** `app/policies/page.tsx`

Client-side page that renders the policies dashboard view. Reads the logged-in user from `localStorage` and redirects to `/` if no session is found. Maps the `agent` role to `admin` for the sidebar display. Renders `<PoliciesTab />` inside the shared sidebar layout.

---

### Users Page

**File:** `app/users/page.tsx`

Client-side page that renders the users management view. Follows the same auth pattern as the Policies page — reads from `localStorage`, redirects if unauthenticated, and maps `agent` → `admin` for the sidebar role. Renders `<UsersTab />` inside the shared sidebar layout.

---

### Environment Variables

Both the credit and users API routes create their own `Pool` instances directly. The policies API imports a shared pool from `@/lib/db`. All routes expect the following environment variables:

| Variable | Description |
|---|---|
| `DB_HOST` | PostgreSQL host |
| `DB_PORT` | PostgreSQL port (default `5432`) |
| `DB_NAME` | Database name |
| `DB_USER` | Database user |
| `DB_PASSWORD` | Database password |
| `NODE_ENV` | Set to `production` to enable SSL |

---

### Notes

- SSL is enabled automatically in production (`NODE_ENV=production`) with `rejectUnauthorized: false`.
- Both page components use `localStorage` for session persistence — this is client-side only and requires the `'use client'` directive.
- The quick-create button on both pages routes to `/claims?create=true`.

---
