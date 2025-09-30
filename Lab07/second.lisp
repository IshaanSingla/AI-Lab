(defun is-even? (number)
  (if (= 0 (mod number 2))
    "It's even!"
    "It's odd!"))

(print (is-even? 10))
(print (is-even? 7))