;; Default Font: Courier 10 Pitch Bold    Size: 15
;; Remember to set CUA-mode and save your options.
(global-set-key (kbd "M-n") 'forward-paragraph)
(global-set-key (kbd "M-p") 'backward-paragraph)
(global-linum-mode t)
(defun compile-cpp ()
  (interactive)
  (compile (format "g++ -o %s %s -g -lm -Wall -std=c++11"  (file-name-sans-extension (buffer-name))(buffer-name))))
(global-set-key (kbd "<f9>") 'compile-cpp)
(global-set-key (kbd "<f8>") 'gud-gdb)
(setq default-tab-width 4)
(setq c-basic-offset 4)
(global-set-key (kbd "RET") 'newline-and-indent)
