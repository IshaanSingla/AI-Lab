
# Lisp Learning Programs

## 1. Aim
The aim of this set of programs is to understand the basic syntax, data structures, and functional programming style of the Lisp programming language through simple example programs.

---

## 2. Programs Overview

### a. `unless-function`
This program defines a custom `unless`-style function in Lisp.

**Code Summary:**
```lisp
(defun unless-function (condition expression)
  (if (not condition)
    expression))
```

**Explanation:**
- The function accepts a `condition` and an `expression`.
- If the condition is false, it evaluates and returns the expression.
- This mimics the behavior of an `unless` statement found in other programming languages.

**Example Usage:**
```lisp
(defvar is-admin t)
(defvar user-password "1234")
(unless-function is-admin (print "Password is:" user-password))
```

If `is-admin` is `t` (true), the body is not executed. If it were false, the password would be printed.

---

### b. CD Database Example

This program demonstrates how to create and manipulate a simple database using Lisp lists and property lists.

**Key Functions:**
1. **Global Database Declaration**
   ```lisp
   (defvar *db* nil)
   ```
   Initializes an empty global list to hold all CD records.

2. **Record Creation**
   ```lisp
   (defun make-cd (title artist rating ripped)
     (list :title title :artist artist :rating rating :ripped ripped))
   ```
   Creates a CD record as a property list (plist).

3. **Add Record Function**
   ```lisp
   (defun add-record (cd)
     (push cd *db*))
   ```
   Adds a new CD record to the beginning of the database list.

**Example Usage:**
```lisp
(defvar cd1 (make-cd "Songs of Faith and Devotion" "Depeche Mode" 9 t))
(defvar cd2 (make-cd "Violator" "Depeche Mode" 10 t))
(defvar cd3 (make-cd "Black Celebration" "Depeche Mode" 10 t))

(add-record cd1)
(add-record cd2)
(add-record cd3)
```

At the end of execution, the `*db*` variable holds a list of all CDs added.

---

### c. Even or Odd Checker

This program defines a simple numeric function to determine if a number is even or odd.

**Code Summary:**
```lisp
(defun is-even? (number)
  (if (= 0 (mod number 2))
    "It's even!"
    "It's odd!"))
```

**Explanation:**
- The function checks whether the remainder of the number divided by 2 equals 0.
- Returns a string message based on the result.

**Example Usage:**
```lisp
(print (is-even? 10)) ; Output: "It's even!"
(print (is-even? 7))  ; Output: "It's odd!"
```

---

## 3. Key Lisp Concepts Demonstrated
- Function definition using `defun`
- Global variable declaration with `defvar`
- Conditional statements using `if` and `not`
- Property lists for structured data representation
- List manipulation using `push`
- Modular and functional programming design

---

## 4. Conclusion
These example programs introduce fundamental Lisp programming techniques, including defining functions, working with lists, and creating simple data-driven programs. They serve as a foundation for learning more advanced Lisp topics such as recursion, higher-order functions, and symbolic processing.