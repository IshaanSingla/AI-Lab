
(defun unless-function (condition expression)
  (if (not condition)
    expression))

(defvar is-admin t)
(defvar user-password "1234")
(unless-function is-admin (print "Password is:" user-password))