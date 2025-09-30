;; 1. The database is a global variable, starting as an empty list (nil).
(defvar *db* nil)

;; 2. A function to create a CD record.
;;    It returns a property list.
(defun make-cd (title artist rating ripped)
  (list :title title :artist artist :rating rating :ripped ripped))

;; 3. A function to add a record to the database.
;;    'push' adds the new cd to the front of the *db* list.
(defun add-record (cd)
  (push cd *db*))


;; --- Let's use your functions ---

;; Create a few records
(defvar cd1 (make-cd "Songs of Faith and Devotion" "Depeche Mode" 9 t))
(defvar cd2 (make-cd "Violator" "Depeche Mode" 10 t))
(defvar cd3 (make-cd "Black Celebration" "Depeche Mode" 10 t))

;; Add the records to the database
(add-record cd1)
(add-record cd2)
(add-record cd3)

